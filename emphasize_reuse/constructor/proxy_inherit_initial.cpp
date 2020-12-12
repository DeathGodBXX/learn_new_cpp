//委托构造函数，继承构造函数
#include <iostream>

class Base
{
public:
    int x;
    int y;
    Base() : x(1) {}
    Base(int vy) : Base() { y = vy; } //委托构造函数
};

class Derived : public Base
{
public:
    using Base::Base; //继承构造函数
};
int main()
{
    Base base1{2}; //使用委托构造函数初始化
    std::cout << base1.x << "\t" << base1.y << std::endl;

    Base base2; //使用不带参数个构造函数初始化
    std::cout << base2.x << "\t" << base2.y << std::endl;

    Derived derived1{33};
    std::cout << derived1.x << "\t" << derived1.y << std::endl;

    Derived derived2;
    std::cout << derived2.x << "\t" << derived2.y << std::endl;
}