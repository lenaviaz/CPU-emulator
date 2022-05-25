#include <iostream>

class console
{

    int read()
    {

        int input;
        std::cout << "enter a character";
        std::cin >> input;
        cout << "" << std::endl;
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