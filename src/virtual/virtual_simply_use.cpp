//虚函数简单使用
#include <iostream>

class Foo
{
public:
    virtual void foo(int x = 1)
    {
        std::cout << "This is Foo::foo()" << std::endl;
    }
};
class FooInherit
{
public:
    virtual void foo(int x = 1)
    {
        std::cout << "This is FooInherit::foo()" << std::endl;
    };
    virtual void foo(float){}; //非法但是系统并为报错；有可能是编译器优化
};

int main()
{
    FooInherit fooinherit;
    Foo foo_class;
    fooinherit.foo();
    foo_class.foo();
}