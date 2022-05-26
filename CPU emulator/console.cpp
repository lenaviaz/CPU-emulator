#include <iostream>

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
        if (0 <= b <= 255)
        {
            char ch = b;
            std::cout << ch << std::endl;
        }
    }
};