//右值引用，将亡值
//字符串字面量只有在类中才是右值，位于普通函数都是左值
#include <iostream>
#include <variant>
#include <string>

int main()
{
    const int &i = 1;
    int const &j = 2;
    if (std::is_same<decltype(i), decltype(j)>::value)
        std::cout << "type i = type j" << std::endl;
    //一样，都是常值引用
}