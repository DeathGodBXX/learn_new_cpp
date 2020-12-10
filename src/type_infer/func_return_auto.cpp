#include <iostream>

//c++11
template <typename T, typename U>
auto add(T x, U y) -> decltype(x + y)
{
    return x + y;
}

//c++14
template <typename T, typename U>
auto add1(T x, U y)
{
    return x + y;
}

//未定义x和y
// template <typename T, typename U>
// decltype(x + y) add3(T x, U y)
// {
//     return x + y;
// }
int main()
{
    //auto w = add(1,2.0);类型推导
    auto w = add<int, float>(1, 2.0);
    if (std::is_same<decltype(w), float>::value)
    {
        std::cout << "type w is float" << std::endl;
    }
    std::cout << "1+2.0=" << w << std::endl;

    //auto s= add1(2.0,1);类型推导
    auto s = add1<float, int>(2.0, 1);
    if (std::is_same<decltype(s), float>::value)
    {
        std::cout << "type s is float" << std::endl;
    }
    std::cout << "2.0+1=" << s << std::endl;
}