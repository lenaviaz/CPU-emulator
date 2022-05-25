using namespace std;
#include "memory.h"
#include "ram.cpp"
#include "mmu.cpp"

int main()
{

    ram r1(15);
    ram r2(20);
    mmu m1;

    m1.attach(5, r1);
    m1.attach(7, r2);

    m1.initialize(5, "h!llo");
    m1.read(6);
    m1.write(6, 125);
    m1.read(6);

    return 0;
}
