
#include "memory.h"
#include <vector>
#include <string>
using namespace std;

class ram : public memory
{

private:
    int size;
    vector<int> capacity;

public:
    ram(int a)
    {
        size = a;
        capacity.reserve(size);
    }

public:
    void write(int address, int a)
    {
        capacity[address] = a;
    }

    void initialize(int address, string word)
    {
        printf("RAM initialize \n");
        for (int i = 0; i < word.length(); i++)
        {
            char a = word[i];
            int ascii = (int)a;
            // printf("%i\n", ascii);

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
        printf("Reading: %i\n", toRead);
        return toRead;

        // for (int i = 0; i < size; i++)
        // {
        //     // printf("index %i holds value %i\n", i, capacity[i]);
        // }
        return 400;
    }

    void printVals()
    {
        for (int i : capacity)
        {
            printf("%i", capacity[i]);
        }
    }
};