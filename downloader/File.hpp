#ifndef __FILE__HPP__
#define __FILE_HPP__
#include <cstdio>
#include <iostream>

class File
{
public:
    void Open(std::string filename, int max);
    int Write(const char* buf, int size);
    void Close();

private:
    FILE* fp;
    int currentSize;
    int maxSize;
};

#endif