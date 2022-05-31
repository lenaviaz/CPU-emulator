#include <iostream>
#include <vector>
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
    int instPointer;
    bool runinstructions;
    std::vector<inst *> cpuInst;

public:
    cpu()
    {
        regPoint = reg;
        instPointer = 0;
        runinstructions = true;

        for (int i = 0; i < 8; i++)
        {
            reg[i] = 0;
        }
    }
    void attachMem(mmu &m)
    {
        m1 = m;
    }

    void addInst(inst &i1)
    {
        cpuInst.push_back(&i1);
        // std::cout << "\n\n"
        //           << i1.getName();
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

    std::vector<inst *> getList()
    {
        return cpuInst;
    }

    void attachIO(int val, console &c1)
    {
        IOman.insert(std::pair<int, console *>(val, &c1));
        // reg[val] = c1.read(); // can remove later
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

    void printRegs()
    {
        std::cout << "\ncpu registers\n";
        for (int i = 0; i < 8; i++)
        {
            std::cout << " | " << reg[i];
        }
        std::cout << "\n\n";
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
            instPointer += 1;
            break;
        }
        case 2:
        {
            loadImm d1(i1->getName(), i1->getSecond(), i1->getThird());
            int add = d1.getThird();
            // int *b = &reg[d1.getSecond()];
            //*b = add;
            reg[d1.getSecond()] = add;
            std::cout << "loadImm" << reg[d1.getSecond()] << std::endl;
            // b = NULL;
            instPointer += 1;
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
            instPointer += 1;
            break;
        }

        case 4:
        {
            store d1(i1->getName(), i1->getSecond(), i1->getThird());
            /*             int a = m1.read(d1.getThird());
                        int *b = &reg[d1.getSecond()];
                        *b = a;
                        b = NULL; */

            int a = reg[d1.getSecond()];
            m1.write(d1.getThird(), a);

            //  std::cout << reg[d1.getSecond()] << std::endl;
            instPointer += 1;
            break;
        }

        case 5:
        {
            InB d1(i1->getName(), i1->getSecond(), i1->getThird());
            for (std::pair<const int, console *> x : IOman)
            {
                int key = x.first;
                console *c = x.second;
                if (key == d1.getThird())
                {
                    reg[d1.getSecond()] = x.second->read();
                }
            }
            instPointer += 1;
            break;
        }
        case 6:
        {
            OutB d1(i1->getName(), i1->getSecond(), i1->getThird());
            int b = reg[d1.getSecond()];

            for (std::pair<const int, console *> x : IOman)
            {
                int key = x.first;
                console *c = x.second;
                if (key = d1.getSecond())
                {
                    x.second->write(b);
                }
                // std::cout << b << "\n";
            }
            instPointer += 1;
        }

        case 7:
        {
            // outnum
        }

        case 8: // outstr
        {
            OutStr d1(i1->getName(), i1->getSecond(), i1->getThird());
            int start = d1.getSecond();

            console con;
            for (std::pair<const int, console *> x : IOman)
            {
                int key = x.first;
                console *c = x.second;
                if (key = d1.getThird())
                {
                    con = *c;
                }
                // std::cout << b << "\n";
            }

            for (int i = start; i >= 0; i++)
            {
                con.write(m1.read(i));
                if (m1.read(i) == 0)
                {
                    instPointer += 1;
                    return;
                }
            }
            break;
        }

        case 9:
        {
            Add d1(i1->getName(), i1->getSecond(), i1->getThird(), i1->getFourth());

            int valA = reg[d1.getSecond()];
            // std::cout << "regA is\n"
            //           << valA;
            int valB = reg[d1.getThird()];
            int valC = reg[d1.getFourth()];

            reg[d1.getFourth()] = valA + valB;
            instPointer += 1;

            break;
        }

        case 10:
        {
            Sub d1(i1->getName(), i1->getSecond(), i1->getThird(), i1->getFourth());

            int valA = reg[d1.getSecond()];
            // std::cout << "regA is\n"
            //           << valA;
            int valB = reg[d1.getThird()];
            int valC = reg[d1.getFourth()];

            reg[d1.getFourth()] = valA - valB;
            instPointer += 1;

            break;
        }

        case 11:
        {
            J d1(i1->getName(), i1->getSecond());
            instPointer += d1.getSecond();

            break;
        }

        case 12:
        {
            JZ d1(i1->getName(), i1->getSecond(), i1->getThird());
            if (reg[d1.getSecond()] == 0)
            {
                instPointer += d1.getThird();
            }
            break;
        }
        case 13:
        {
            JNZ d1(i1->getName(), i1->getSecond(), i1->getThird());
            if (reg[d1.getSecond()] != 0)
            {
                instPointer += d1.getThird();
                std::cout << instPointer;
            }
            break;
        }

        case 14:
        {
            JReg d1(i1->getName(), i1->getSecond());
            instPointer += reg[d1.getSecond()];
            break;
        }
        case 15:
        {
            Halt d1(i1->getName());
            runinstructions = false;
            break;
            // end
        }
        }
    };

    void run()
    {
        for (int i = 0; i < 10000000; i++)
        {
            evalInst(cpuInst.at(instPointer));
        }
    }
};
#endif