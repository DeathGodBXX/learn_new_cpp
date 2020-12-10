// 默认模板参数的使用
#include <iostream>

template <typename T = int, typename U = int>
auto add(T x, U y)
{
    return x + y;
}

int main()
{
    std::cout << add(1, 2) << std::endl;
    std::cout << add(1.0, 2) << std::endl;
}