//显示声明采取或拒绝编译器自带的函数
#include <iostream>

class Magic
{
public:
    int x;
    Magic() = default; //显示声明采取编译器默认的构造函数
    Magic(int num) : x(num)
    {
        std::cout << "Magic::Magic(int)" << std::endl;
    }
    Magic &operator=(const Magic &) = delete; //显示声明拒绝编译器默认的赋值运算符重载
    Magic &operator=(Magic &magic)
    {
        std::cout << "This is Magic::operator=" << std::endl;
        return magic;
    }
};
int main()
{
    Magic magic;
    Magic magic1(2);
    magic = magic1;
}