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
    ram r1(15); // allocating one chunk of ram of size 15
    ram r2(20); // allocating one chunk of ram size 20
    console c1;
    console c2;
    mmu m1;
    m1.attach(0, r1);
    m1.attach(16, r2); // won't attach at 15 deal with later
    cpu comp;

    comp.attachMem(m1);
    comp.attachIO(5, c1);
    // comp.regControl(4);

    // comp.printIOmap();

    ldata f1("ldata", 5, "I'm Lena!0");
    loadImm f2("loadImm", 1, 35);
    // load f3("load", 2, 6);
    // store f4("store", 3, 6);
    // offset f2("offset", 5);
    OutB f3("OutB", 1, 5);
    OutStr f4("OutStr", 5, 5);
    Add f5("Sub", 5, 1, 6);

    comp.addInst(f1);
    comp.addInst(f2);
    comp.addInst(f3);

    comp.run(comp.getList());

    // comp.evalInst(&f1);
    // comp.evalInst(&f2);
    // comp.evalInst(&f5);

    // c1.write(33);
    // comp.evalInst(&f3);
    //  comp.evalInst(&f3);
    // comp.evalInst(&f4);

    comp.printRegs();
    return 0;
}
