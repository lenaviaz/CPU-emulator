#include <string>;
using namespace std;

class memory
{
public:
    virtual void initialize(int address, string word);

    virtual int read(int address);

    virtual void write(int address, int a);

    virtual int getSize();
};