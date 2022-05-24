#include "memory.cpp";
#include <unordered_map>
using namespace std;

class mmu : public memory
{

    std::unordered_map<int, memory> myMap();

public:
    mmu()
    {
    }

    void attach(int address, memory m1)
    {
    }

    void initialize(int address, string word)
    {
    }

    int read(int address)
    {
    }

    int getSize()
    {
    }

    void write(int address, int a)
    {
    }
};