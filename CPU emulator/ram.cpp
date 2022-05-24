
#include "memory.h"
#include <string>
using namespace std;

class ram : public memory
{

private:
    int size;
    int capacity[];

public:
    ram(int a)
    {
        size = a;
        capacity[size];
    }

public:
    void initialize(int address, string word)
    {
        printf("RAM initialize ");
        for (int i = 0; i < word.length(); i++)
        {
            char a = word[i];
            int ascii = (int)a;

            capacity[address] = ascii;
            address++;
        }
    }

    int getSize()
    {
        return size;
    }

    int read(int address)
    {
        int toRead = capacity[address];
        return toRead;
    }

    void write(int address, int a)
    {
        capacity[address] = a;
    }
};