#include <iostream>
#include "console.cpp"
#include "mmu.cpp"
#include "mmu.cpp"
#include "inst.h"
#include "instructions.cpp"
#ifndef CPU_CPP
#define CPU_CPP
class cpu
{

private:
    int reg[8];
    int *regPoint;
    mmu m1;
    map<int, console *> IOman;

public:
    cpu()
    {
        regPoint = reg;
    }
    void attachMem(mmu &m)
    {
        m1 = m;
    }

    void printIOmap()
    {
        for (std::pair<const int, console *> x : IOman)
        {
            int key = x.first;
            console *c = x.second;
            std::cout << key << "\n"
                      << std::endl;
        }
    }

    void attachIO(int val, console &c1)
    {
        IOman.insert(std::pair<int, console *>(val, &c1));
        reg[val] = c1.read();
        std::cout << "attached" << std::endl;
    }

    bool regControl(int check)
    {
        for (std::pair<const int, console *> x : IOman)
        {
            int key = x.first;
            if (key == check)
                std::cout << "this register is NOT available"
                          << "\n"
                          << std::endl;
            return false;
        }
        std::cout << "this register is available"
                  << "\n"
                  << std::endl;
        return true;
    }
    void evalInst(inst *i1)
    {
        // std::cout << d1.getName() << d1.getSecond() << d1.getThirdString() << std::endl;
        switch (i1->getNum())
        {
        case 0:
        {
            std::cout << "base class was called" << std::endl;
            break;
        }
        case 1:
        {
            ldata d1(i1->getName(), i1->getSecond(), i1->getThirdString());
            // std::cout << d1.getName() << d1.getSecond() << d1.getThirdString() << std::endl;
            m1.initialize(d1.getSecond(), d1.getThirdString());
            break;
        }
        case 2:
        {
            loadImm d1(i1->getName(), i1->getSecond(), i1->getThird());
            int add = d1.getThird();
            int *b = &reg[d1.getSecond()];
            *b = add;
            std::cout << reg[d1.getSecond()] << std::endl;
            b = NULL;
            break;
        }

        case 3:
        {
            load d1(i1->getName(), i1->getSecond(), i1->getThird());
            int add = m1.read(d1.getThird());
            int *b = &reg[d1.getSecond()];
            *b = add;
            std::cout << reg[d1.getSecond()] << std::endl;
            b = NULL;
            break;
        }

        case 4:
        {
            store d1(i1->getName(), i1->getSecond(), i1->getThird());
            int a = m1.read(d1.getThird());
            int *b = &reg[d1.getSecond()];
            *b = a;
            b = NULL;
            std::cout << reg[d1.getSecond()] << std::endl;
            break;
        }

        case 5:
        {
            InB d1(i1->getName(), i1->getSecond(), i1->getThird());

            for (std::pair<const int, console *> x : IOman)
            {
                int key = x.first;
                console *c = x.second;
                if (key = d1.getThird())
                {
                    reg[d1.getSecond()] = x.second->read();
                }
            }

            break;
        }
        }
    }
};
#endif