#include <iostream>

class Apple
{
public:
    static void printmsg() { std::cout << "Message" << std::endl; };
};

int main()
{
    Apple::printmsg();
    Apple apl;
    apl.printmsg();
}