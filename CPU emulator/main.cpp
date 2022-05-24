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
    // m1.printVals();

    m1.initialize(12, "hhhhh");
    int a = m1.read(14);
    // printf("%i", a);

    // string a = "hello";
    // char b = a[3];
    // int ascii = (int)b;

    // printf("%i", ascii);
    //  r1.initialize(12, "hello");
    //  r1.read(12);

    return 0;
}
