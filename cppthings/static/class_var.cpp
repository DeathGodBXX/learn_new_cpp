//c++11/14之前，Apple::b只是常量表达式，不分配内存，但是c++17/20以后，都是可以分配内存的，show(int)
//但是仍然不能把形参int&绑定到static constexpr类型，const限定符会丢失，show1(int &),可以绑定到show2(const int &)
#include <iostream>

class Apple
{
public:
    static int a;
    static constexpr int b = 20;
};

int Apple::a = 10;
//只是静态变量，必须要在声明之后定义(初始化)，分配内存,否值链接会报错undefined referenece to Apple::a
//而且只能在main函数外，main内部不容许
// int Apple::b;  //c++17之后，都不需要显示声明了

void show(int i)
{
    std::cout << i << std::endl;
}
void show1(int &i)
{
    std::cout << i << std::endl;
}

void show2(const int &i) //如果不加const，限制符会丢失(编译不过)
{
    std::cout << i << std::endl;
}

int main()
{
    std::cout << Apple::b << std::endl;
    show(Apple::b);
    show2(Apple::b);
}
