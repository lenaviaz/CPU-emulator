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
    ram r1(50); // allocating one chunk of ram of size 15
    ram r2(30); // allocating one chunk of ram size 20
    console c1;
    console c2;
    mmu m1;
    m1.attach(0, r1);
    m1.attach(100, r2);
    // m1.attach(16, r2); // won't attach at 15 deal with later
    cpu comp;

    comp.attachMem(m1);
    comp.attachIO(0, c1);
    // comp.regControl(4);

    // comp.printIOmap();

    // start of CPI instructions for fib
    ldata f1("ldata", 5, "Please enter a number between 0 and 9");
    OutStr f2("OutStr", 5, 0);
    InB f3("InB", 4, 0);
    loadImm sp("LoadImm", 7, 1);
    loadImm f4("LoadImm", 1, 0);
    loadImm f5("LoadImm", 2, 1);
    Add f6("Add", 1, 2, 3);
    store f7("store", 2, 100);
    load f8("load", 1, 100);
    store f9("store", 3, 101);
    load f10("load", 2, 101);
    Sub f11("Sub", 4, 7, 4);
    JZ check("JZ", 4, 2);
    JNZ f12("JNZ", 4, -6);
    ldata f13("ldata", 105, "fibbonacci is: ");
    OutStr f14("OutStr", 105, 0);
    OutB f15("OutB", 1, 0);
    Halt f16("Halt");
    // all initializing stuff

    comp.addInst(f1);
    comp.addInst(f2);
    comp.addInst(f3);
    comp.addInst(sp);
    comp.addInst(f4);
    comp.addInst(f5);
    comp.addInst(f6);
    comp.addInst(f7);
    comp.addInst(f8);
    comp.addInst(f9);
    comp.addInst(f10);
    comp.addInst(f11);
    // comp.addInst(check);
    comp.addInst(f12);
    comp.addInst(f13);
    comp.addInst(f14);
    comp.addInst(f15);
    comp.addInst(f16);
    comp.run();

    comp.printRegs();
    return 0;
}
