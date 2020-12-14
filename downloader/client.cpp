#include <boost/asio.hpp> 
#include <iostream> 

void sendData(boost::asio::ip::tcp::socket& socket, const std::string& message) 
{ 
	write(socket, 
		boost::asio::buffer(message + "\n")); 
} 

int main(int argc, char* argv[]) 
{ 
	boost::asio::io_service io_service; 
	// socket creation 
	boost::asio::ip::tcp::socket client_socket(io_service); 

	client_socket 
		.connect( 
			boost::asio::ip::tcp::endpoint( 
				boost::asio::ip::address::from_string("127.0.0.1"), 
				9999)); 

	std::cout << "Enter your name: "; 
	std::string u_name, reply, response; 
	getline(std::cin, u_name); 

	sendData(client_socket, u_name); 

	while (true) { 
		std::cout << u_name << ": "; 
		getline(std::cin, reply); 
		sendData(client_socket, reply); 

		if (reply == "exit") 
			break; 
	} 
	return 0; 
} 
