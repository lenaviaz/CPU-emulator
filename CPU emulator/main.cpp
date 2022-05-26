#include <iostream>
#include "memory.h"
#include "ram.cpp"
#include "mmu.cpp"
#include "console.cpp"

int main()
{
    ram r1(15);
    ram r2(20);
    console c1;
    mmu m1;
    m1.attach(0, r1);
    m1.attach(16, r2); // won't attach at 15 deal with later

    m1.printVals();

    m1.initialize(5, "h!llo");
    // int b = c1.read();
    // m1.read(5);
    c1.read();
    //  m1.write(6, 125);
    //  m1.read(6);

    return 0;
}
