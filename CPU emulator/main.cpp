#include <iostream>
#include "memory.h"
#include "ram.cpp"
#include "mmu.cpp"
#include "console.cpp"
#include "inst.h"
#include "cpu.cpp"
#include "instructions.cpp"

int main()
{
    ram r1(15);
    ram r2(20);
    console c1;
    mmu m1;
    m1.attach(0, r1);
    m1.attach(16, r2); // won't attach at 15 deal with later
    cpu comp;

    comp.attachMem(m1);

    ldata f1("ldata", 5, "h!llo");
    loadImm f2("loadImm", 1, 1999);
    load f3("load", 2, 6);
    // offset f2("offset", 5);

    comp.evalInst(&f1);
    comp.evalInst(&f2);
    comp.evalInst(&f3);

    return 0;
}
