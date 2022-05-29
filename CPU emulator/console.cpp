#include <iostream>
#ifndef CONSOLE_CPP
#define CONSOLE_CPP
class console
{
public:
    int read()
    {

        char input;
        std::cout << "enter a character\n";
        std::cin >> input;
        std::cout << "" << std::endl;

        int a = (int)input;
        std::cout << a << std::endl;
        return input;
    }

    void write(int b)
    {
        if (0 <= b && b <= 255)
        {
            char ch = b;
            std::cout << "write called\n"
                      << ch << std::endl;
        }
    }
};
#endif