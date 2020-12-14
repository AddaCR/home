#include "File.hpp"

void File::Open(std::string filename, int max)
{
    fp = fopen(filename.c_str(), "a+");
    std::cout << "Filename: " << filename << std::endl;
    maxSize = max;
    currentSize = 0;
}

int File::Write(const char* buf, int size)
{
    if(fp == nullptr) {
        std::cout<<"no"<<std::endl;
        return -1;
    }
    if(currentSize >= maxSize) {
        return 0;
    }
    int toWrite = size;
    if(currentSize + size >= maxSize)
    {
        toWrite = maxSize - currentSize;
    }
    int count = fwrite(buf, sizeof(char), toWrite, fp);
    currentSize += count * sizeof(char);
    return count * sizeof(char);
}

void File::Close()
{
    fclose(fp);
    fp = nullptr;
}