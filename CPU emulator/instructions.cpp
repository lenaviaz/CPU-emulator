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

class OutB : public inst
{
private:
    std::string name;
    int reg;
    int port;

public:
    OutB(std::string a, int b, int c)
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
        return 6;
    }
};

class OutNum : public inst
{

public:
    int getNum()
    {
        return 7;
    }
};

class OutStr : public inst
{
private:
    std::string name;
    int addr;
    int port;

public:
    OutStr(std::string a, int b, int c)
    {
        name = a;
        addr = b;
        port = c;
    }

    std::string getName()
    {
        return name;
    }

    int getSecond()
    {
        return addr;
    }

    int getThird()
    {
        return port;
    }
    int getNum()
    {
        return 8;
    }
};

class Add : public inst
{
private:
    std::string name;
    int regA;
    int regB;
    int regC;

public:
    Add(std::string n, int a, int b, int c)
    {
        name = n;
        regA = a;
        regB = b;
        regC = c;
    }

    std::string getname()
    {
        return name;
    }

    int getSecond()
    {
        return regA;
    }

    int getThird()
    {
        return regB;
    }

    int getFourth()
    {
        return regC;
    }

    int getNum()
    {
        return 9;
    }
};

class Sub : public inst
{
private:
    std::string name;
    int regA;
    int regB;
    int regC;

public:
    Sub(std::string n, int a, int b, int c)
    {
        name = n;
        regA = a;
        regB = b;
        regC = c;
    }

    std::string getname()
    {
        return name;
    }

    int getSecond()
    {
        return regA;
    }

    int getThird()
    {
        return regB;
    }

    int getFourth()
    {
        return regC;
    }

    int getNum()
    {
        return 10;
    }
};

class J : public inst
{
private:
    std::string name;
    int offset;

public:
    J(std::string a, int b)
    {
        name = a;
        offset = b;
    }

    std::string getName()
    {
        return name;
    }

    int getSecond()
    {
        return offset;
    }

    int getNum()
    {
        return 11;
    }
};

class JZ : public inst
{
private:
    std::string name;
    int reg;
    int offset;

public:
    JZ(std::string a, int b, int c)
    {
        name = a;
        reg = b;
        offset = c;
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
        return offset;
    }
    int getNum()
    {
        return 12;
    }
};

class JNZ : public inst
{
private:
    std::string name;
    int reg;
    int offset;

public:
    JNZ(std::string a, int b, int c)
    {
        name = a;
        reg = b;
        offset = c;
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
        return offset;
    }
    int getNum()
    {
        return 13;
    }
};

class JReg : public inst
{
private:
    std::string name;
    int reg;

public:
    JReg(std::string a, int b)
    {
        name = a;
        reg = b;
    }

    std::string getName()
    {
        return name;
    }

    int getSecond()
    {
        return reg;
    }

    int getNum()
    {
        return 14;
    }
};

class Halt : public inst
{
private:
    std::string name;

public:
    Halt(std::string a)
    {
        name = a;
    }

    std::string getName()
    {
        return name;
    }

    int getNum()
    {
        return 15;
    }
};

#endif