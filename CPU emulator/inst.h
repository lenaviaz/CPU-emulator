#ifndef INSTRUCTION_H
#define INSTRUCTION_H
//#include <iostream>
class inst
{
public:
    virtual std::string getName()
    {
        return "0";
    }

    virtual int getSecond()
    {
        return 0;
    }

    virtual std::string getThirdString()
    {
        return "0";
    }

    virtual int getThird()
    {
        return 0;
    }

    virtual int getNum()
    {
        return 0;
    }
};
#endif