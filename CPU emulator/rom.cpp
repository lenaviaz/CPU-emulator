#include "memory.cpp";
using namespace std;

class rom : public memory
{

private:
    int size;
    int capacity[];

public:
    rom(int a)
    {
        size = a;
        capacity[size];
    }

public:
    void initialize(int address, string word)
    {
        printf("ROM initialize ");
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
        // do nothing
    }
};