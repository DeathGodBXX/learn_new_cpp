//绑定调用函数的参数 std::bind,std::placeholder
#include <iostream>
#include <functional>

void foo(int x, int y, int z)
{
    std::cout << "x=" << x
              << ",\ty=" << y
              << ",\tz=" << z << std::endl;
}
int main()
{
    std::function<void(int, int, int)> fo = foo;
    auto bindfo = std::bind(fo, std::placeholders::_1, 1, 2);
    bindfo(0);
}