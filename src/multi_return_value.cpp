//结构化绑定完成多返回值的函数
#include <iostream>
#include <tuple>

std::tuple<int, float, std::string> f()
{
    return std::make_tuple(1, 2.3, "abcd");
}

int main()
{
    auto [x, y, z] = f();
    std::cout << "x=" << x << "\ty=" << y << "\tz=" << z << std::endl;
}