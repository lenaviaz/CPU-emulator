using namespace std;
#include "memory.h"
#include "ram.cpp"
#include "mmu.cpp"

int main()
{

    ram r1(1000);
    ram r2(2000);
    ram r3(25);
    mmu m1;
    //  ram r1(1000);
    // ram r1(1000);

    m1.attach(10, r1);
    m1.attach(2000, r2);
    m1.attach(3000, r3);

    // int a = r1.getSize();
    // printf("size is:  %i\n", a);
    m1.printVals();

    return 0;
}
