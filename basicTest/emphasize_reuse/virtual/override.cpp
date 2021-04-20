//override 显示声明虚函数重载
#include <iostream>

class Base
{
public:
    virtual void foo(int){};
};

class Derived : Base
{
public:
    virtual void foo(int) override
    {
        std::cout << "This is Derived::foo()" << std::endl;
    }
    // virtual void foo(float) override{}; //非法
};
int main()
{
}