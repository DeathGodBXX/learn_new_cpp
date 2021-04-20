//static变量
#include <iostream>

void demo()
{
    static int count = 1;
    std::cout << count << std::endl;
    count++;
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        demo();
    }
}