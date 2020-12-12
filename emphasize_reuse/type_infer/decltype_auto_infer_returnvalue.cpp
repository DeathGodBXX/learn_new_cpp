//封装确定类型的函数，利用auto推断返回值类型
#include <iostream>
#include <string>

std::string str_get()
{
    return "ok";
}

//返回string类型的引用，而在函数内部定义变量，不能传到外部；故而需要传递一个string类型的引用变量
std::string &str_get_by_quote(std::string &str)
{
    str = "ok";
    return str;
}

//也可以使用auto
decltype(auto) str_get_wrap()
{
    return str_get();
}

//也可以使用auto
decltype(auto) str_get_by_quote_wrap(std::string &str)
{
    return str_get_by_quote(str);
}

int main()
{
    std::cout << str_get_wrap() << std::endl;

    std::string str;
    str_get_by_quote_wrap(str);
    std::cout << str << std::endl;
}