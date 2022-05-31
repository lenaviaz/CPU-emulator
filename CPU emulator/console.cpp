#include <iostream>
#ifndef CONSOLE_CPP
#define CONSOLE_CPP
class console
{
public:
    int read()
    {

        char input;
        std::cout << "\n";
        std::cin >> input;
        std::cout << "" << std::endl;

        int a = (int)input - 48;
        std::cout << a << std::endl;
        return a;
    }

    void write(int b)
    {
        if (0 <= b && b <= 255)
        {
            char ch = b;
            std::cout
                << ch;
        }
    }

    void outNum(int b)
    {
        std::cout << b << endl;
    }
};
#endif