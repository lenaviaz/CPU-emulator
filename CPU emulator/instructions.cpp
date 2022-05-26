#include "inst.h"
#include <iostream>

#ifndef INSTRUCTIONS_CPP
#define INSTRUCTIONS_CPP
class ldata : public inst
{

private:
    std::string name;
    int address;
    std::string chars;

public:
    ldata(std::string a, int b, std::string c)
    {
        name = a;
        address = b;
        chars = c;
    }

    std::string getName()
    {
        return name;
    }

    int getSecond()
    {
        return address;
    }

    std::string getThirdString()
    {
        return chars;
    }

    int getNum()
    {
        return 1;
    }

    void message()
    {
        std::cout << "data called\n"
                  << std::endl;
    }
};

class loadImm : public inst
{
private:
    std::string name;
    int reg;
    int number;

public:
    loadImm(std::string a, int b, int c)
    {
        name = a;
        reg = b;
        number = c;
    }

    std::string getName()
    {
        return name;
    }

    int getSecond()
    {
        return reg;
    }

    int getThird()
    {
        return number;
    }

    int getNum()
    {
        return 2;
    }
};

class load : public inst
{

private:
    std::string name;
    int reg;
    int address;

public:
    load(std::string a, int b, int c)
    {
        name = a;
        reg = b;
        address = c;
    }

    std::string getName()
    {
        return name;
    }

    int getSecond()
    {
        return reg;
    }
    int getThird()
    {
        return address;
    }

    int getNum()
    {
        return 3;
    }
};

class store : public inst
{

private:
    std::string name;
    int reg;
    int address;

public:
    store(std::string a, int b, int c)
    {
        name = a;
        reg = b;
        address = c;
    }

    std::string getName()
    {
        return name;
    }

    int getSecond()
    {
        return reg;
    }

    int getThird()
    {
        return address;
    }

    int getNum()
    {
        return 4;
    }
};

class InB : public inst
{

private:
    std::string name;
    int reg;
    int port;

public:
    InB(std::string a, int b, int c)
    {
        name = a;
        reg = b;
        port = c;
    }

    std::string getName()
    {
        return name;
    }

    int getSecond()
    {
        return reg;
    }

    int getThird()
    {
        return port;
    }

    int getNum()
    {
        return 5;
    }
};

//////////////////////////////////////////////////
class offset : public inst
{
private:
    std::string name;
    int numOffset;

public:
    offset(std::string a, int b)
    {
        name = a;
        numOffset = b;
    }

    std::string getName()
    {
        return name;
    }

    int getSecond()
    {
        return numOffset;
    }

    int getNum()
    {
        return 3;
    }
};

#endif