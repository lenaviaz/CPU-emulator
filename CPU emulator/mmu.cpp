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

        if (true)
        {
        }
    }

    void initialize(int address, string word)
    {
        for (std::pair<const int, memory *> x : myMap)
        {
            int key = x.first;
            memory *m = x.second;
            int size = x.second->getSize();

            int check = key + size;

            if (key <= address && check > address)
            {
                int adjust = address - key;
                x.second->initialize(adjust, word);
                break;
            }
        }
    }

    int read(int address)
    {

        for (std::pair<const int, memory *> x : myMap)
        {
            int key = x.first;
            memory *m = x.second;
            int size = x.second->getSize();

            int check = key + size;

            if (key <= address && check > address)
            {
                int adjust = address - key;
                return x.second->read(adjust);
            }
        }
        return 404;
    }

    int getSize()
    {
        return 0; // placeholder
    }

    void write(int address, int a)
    {

        for (std::pair<const int, memory *> x : myMap)
        {
            int key = x.first;
            memory *m = x.second;
            int size = x.second->getSize();

            int check = key + size;

            if (key <= address && check > address)
            {
                int adjust = address - key;
                x.second->write(adjust, a);
            }
        }
    }

    void printVals()
    {
        for (std::pair<const int, memory *> x : myMap)
        {
            int a = x.second->getSize();
            printf("Attached at address:%i\n", x.first);
            printf("Size: %i\n                                                                                                                                                                                                       ", a);
            // printf("%i\n", a);
        }
    }
};
