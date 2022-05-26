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

public:
    cpu()
    {
        regPoint = reg;
    }
    void
    attachMem(mmu &m)
    {
        m1 = m;
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

            break;
        }

        case 5:
        {
            InB d1(i1->getName(), i1->getSecond(), i1->getThird());

            break;
        }
        }
    }
};
#endif