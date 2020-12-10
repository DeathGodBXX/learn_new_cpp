//折叠表达式
#include <iostream>

template <typename... T>
auto Add(T... t)
{
    return (t + ...);
}

template <auto value>
void printf()
{
    std::cout << value << std::endl;
}
int main()
{
    std::cout << Add(1, 2.0, 3.1111, 4, 2.0) << std::endl;
    printf<100>();
}