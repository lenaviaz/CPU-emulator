#include "memory.h"
#include <map>
#include <iostream>
// using namespace std;
#ifndef MMU_CPP
#define MMU_CPP
class mmu : public memory
{
public:
    map<int, memory *> myMap;

public:
    bool checkMap(int address, memory &m1)
    {

        if (myMap.empty())
        {
            return true;
        }

        for (std::pair<const int, memory *> x : myMap)
        {

            int key = x.first;
            int size = x.second->getSize();
            if (key <= address <= size - 1)
            {
                return false;
            }
        }

        return true;
    }

    void attach(int address, memory &m1)
    {
        bool check = true;
        for (std::pair<const int, memory *> x : myMap)
        {

            int key = x.first;
            int size = x.second->getSize();
            if (address < key || address > size)
            {
                check = true;

                // std::cout << "mem overlap" << std::endl;
                // return;
            }
            else
            {
                check = false;
                std::cout << "mem overlap" << std::endl;
                return;
            }
        }

        myMap.insert(std::pair<int, memory *>(address, &m1));

        // if (checkMap(address, m1))
        // {
        //     myMap.insert(std::pair<int, memory *>(address, &m1));
        // }
        // else
        // {
        //     std::cout << "cannot attach - memory overlap" << std::endl;
        // }
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
        return 9999;
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
            std::cout << "attached at address\n";
            std::cout << x.first;
            std::cout
                << a
                << endl;
            // std::endl;
            /// std::cout << ("Attached at address:%i\n", x.first) << std::endl;
            // printf("Size: %i\n                                                                                                                                                                                                       ", a);
            // printf("%i\n", a);
        }
    }
};
#endif