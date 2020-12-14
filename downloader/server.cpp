#include "File.hpp"

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include <boost/asio.hpp> 
#include <ctime>
#include <sstream>
#include <fstream>
#include <chrono>
#include <thread>
#include <memory>
#include <csignal>
#include <functional>

int port;
std::string prefix;
int maxSize;
int timer;
int clientId = 0;
int bufsize;

std::atomic<bool> isShutdown(false);

void sigHandler(int arg)
{
    isShutdown.store(true);
}

// Generates filename
std::string name_generator(std::string prefix, int id, int count)
{
    char buf[200];
    time_t now = time(nullptr);
    struct tm *tmTime = gmtime(&now);
    sprintf(buf, "%s_%i_%i_%i%02i%02i%02i%02i%02i", prefix.c_str(),
            id, count, tmTime->tm_year + 1900 , tmTime->tm_mon + 1 , tmTime->tm_mday 
              , tmTime->tm_hour , tmTime->tm_min , tmTime->tm_sec);
    return std::string(buf);
}

void config()
{
    //set variables for configurable parameters 
    FILE* fp = fopen("config.json", "r");
 
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    rapidjson::Document d;
    d.ParseStream(is);

    port = d["port"].GetInt();
    prefix = d["prefix"].GetString();
    maxSize = d["maxSize"].GetInt();
    timer = d["timer"].GetInt();
    bufsize = d["buffersize"].GetInt();

    fclose(fp);
}

// receiving data from buffer 
int getData(boost::asio::ip::tcp::socket& socket, std::vector<char> &buffer) 
{ 
    boost::system::error_code ec;
    std::size_t length = socket.read_some(boost::asio::buffer(buffer), ec);
	
    if(ec && ec != boost::asio::error::would_block) 
    {
        std::cout << "Got error: " << ec << std::endl;
        return -1;
    }
    else
    {
        return length;
    }
} 


void doClient(std::shared_ptr<boost::asio::ip::tcp::socket> server_socket_shared, int id)
{
    auto &server_socket = *server_socket_shared;
    server_socket.non_blocking(true);

    std::chrono::duration<float> active_time = std::chrono::seconds(timer);

    std::cout<<"accept"<<std::endl;

    // setup client read loop
    int openCount = 0;
    File f;
    f.Open(name_generator(prefix, id, openCount), maxSize);

    std::string response;
    std::vector<char> buffer;
    buffer.resize(bufsize);

    auto start = std::chrono::system_clock::now();
	while (true) { 
        if(isShutdown.load())
        {
            f.Close();
            break;
        }
		// Fetching response 
        std::cout<<"waiting for client message"<<std::endl;

        auto end = std::chrono::system_clock::now();
        std::chrono::duration<float> elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(end - start);
        std::cout<<elapsed_time.count()<<std::endl; 
        if(elapsed_time.count() > active_time.count()) {
            std::cout << "Timer stopped " << std::endl;
            f.Close();
            server_socket.close();
            break;
        }
        int size = 0;
        try {
            size = getData(server_socket, buffer); 
            if(size == -1)
            {
                f.Close();
                break;
            }
        } catch(std::runtime_error &e) {
            std::cout << "Got error " << e.what() << " while reading" << std::endl;
            f.Close();
            server_socket.close();
            break;
        }
        std::cout<<"Got message"<<std::endl;
        int index = 0;
        while(size > 0)
        {
            start = std::chrono::system_clock::now();
            std::cout << "Index: " << index << " size: ";
            int written = f.Write(&buffer[index],size);
            std::cout << " Written: " << written << std::endl;
            if(written == size)
            {
                break;
            }

            if(written < size)
            {
                f.Close();
                openCount++;
                f.Open(name_generator(prefix, id, openCount), maxSize);
                index += written;
                size = size - written;
            }
        }
        std::cout<<&buffer[0]<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
	} 
}


void run()
{

    //setup server:
    //             - server objects

    boost::asio::io_service io_service; 
    boost::asio::ip::tcp::acceptor acceptor_server( 
		io_service, 
		boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)); 

    //             - create socket

    std::thread acceptorThread = std::thread([&] {
        while(isShutdown.load() == false)
        {
                auto server_socket = std::make_shared<boost::asio::ip::tcp::socket>(io_service);

                acceptor_server.accept(*server_socket);
                std::thread clientThread(doClient, server_socket, clientId);
                clientThread.detach();
                clientId++;
        }
    }
    );

    while(isShutdown.load() == false)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    kill(getpid(), SIGKILL);
    acceptor_server.close();
    acceptorThread.join();
}

int main(int argc, char* argv[]) 
{ 
    signal(SIGINT, sigHandler);
    config();
    run();
	return 0; 
} 
