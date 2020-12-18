#include <iostream>

class Apple
{
public:
    static int i;

    Apple(){
        // Do nothing
    };
};

int Apple::i;
int main()
{
    Apple obj1;
    Apple obj2;
    obj1.i = 2;
    obj2.i = 3;

    // prints value of i
    std::cout << obj1.i << " " << obj2.i << std::endl;
}