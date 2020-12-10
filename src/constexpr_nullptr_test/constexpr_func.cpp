#include <iostream>

constexpr int fabonacci(int n)
{
    return n == 1 || n == 2 ? 1 : fabonacci(n - 1) + fabonacci(n - 2);
}

constexpr int fabonacci_11(int n) //c++11不能通过编译，c++14能够写简单的循环，条件，赋值等语句
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    return fabonacci_11(n - 1) + fabonacci_11(n - 2);
}
int main()
{
    std::cout << fabonacci(10) << std::endl;
    std::cout << fabonacci_11(10) << std::endl;
}