#include "memory.h"
#include <map>
#include <iostream>
using namespace std;

class mmu : public memory
{
public:
    map<int, memory *> myMap;

public:
    void attach(int address, memory &m1)
    {
        myMap.insert(std::pair<int, memory *>(address, &m1));

        // myMap[address] = &m1;
    }

    void initialize(int address, string word)
    {

        // int key
        // memory m
    }

    int read(int address)
    {
        return 5; // placeholder
    }

    int getSize()
    {
        return 0; // placeholder
    }

    void write(int address, int a)
    {
    }

    void printVals()
    {
        for (std::pair<const int, memory *> x : myMap)
        // for (memory x : myMap)
        {
            int a = x.second->getSize();
            printf("Attached at address:%i\n", x.first);
            printf("Size: %i\n", a);
            // printf("%i\n", a);
        }
    }
};
