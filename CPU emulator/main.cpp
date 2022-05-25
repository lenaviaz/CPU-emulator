using namespace std;
#include "memory.h"
#include "ram.cpp"
#include "mmu.cpp"

int main()
{

    ram r1(15);
    mmu m1;

    m1.attach(5, r1);

    m1.initialize(5, "hello");
    m1.read(6);

    return 0;
}
