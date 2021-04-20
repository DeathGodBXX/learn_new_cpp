//final 禁用类的继承和虚函数重载
#include <iostream>

class Base
{
public:
    virtual void foo(int) final
    {
        std::cout << "This is Base::foo()" << std::endl;
    }
};

class Subclass1 final : Base
{
};
//报错
// class Subclass2 : Subclass1
// {
// };
// class Subclass3 : Base
// {
//     virtual void foo(int){};
// };
int main()
{
}
