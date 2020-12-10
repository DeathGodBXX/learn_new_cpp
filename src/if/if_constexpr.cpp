//利用if_else生成两份参数类型不同函数定义(分派)
#include <iostream>

template <typename T>
auto add(const T &t) //t必须声明成const类型，否则add(3),add(3.0)无法匹配
{
    //必须使用if_else，不能if_return之后，再return,因为这样模板推断add类型就是int，而不是double
    //也就是不会生成int_double两份函数说明

    //c++17
    if constexpr (std::is_integral<T>::value)
    {
        return t + 1;
    }
    else
    {
        return t + 0.001;
    }
}

int main()
{
    std::cout << add(3) << std::endl;
    std::cout << add(3.0) << std::endl;
}