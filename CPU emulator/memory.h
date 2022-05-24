#ifndef MEMORY_H
#define MEMORY_H
#include <string>
using namespace std;

class memory
{
public:
    virtual void initialize(int address, string word)
    {
        printf("hi");
    }

    virtual int read(int address)
    {
        return 0;
    }

    virtual void write(int address, int a)
    {
        printf("hi");
    }

    virtual int getSize() = 0;
};

#endif