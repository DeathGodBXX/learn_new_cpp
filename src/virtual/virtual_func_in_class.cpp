//虚函数的重载与覆盖
#include <iostream>

class Base
{
public:
    virtual void f() const //加const,表明f不会修改class Base的成员变量
    {
        std::cout << "Base::f()" << std::endl;
    }
};

class Derived : public Base //如果不加public,show函数无法访问Base
{
public:
    virtual void f()
    {
        std::cout << "Derived::f()" << std::endl;
    }
};

void show(Base &b) //使用& 引用用于修改外部变量指
{
    b.f();
}

int main()
{
    Base base;
    Derived derived;
    show(base);
    show(derived);
    base.f();
    derived.f();
}

/*运行结果是：
    Base::f()
    Base::f()
    Base::f()
    Derived::f()
如果删除Base后面的const或者给Derived的f函数后添加const,运行结果：
    Base::f()
    Derived::f()
    Base::f()
    Derived::f()

原因：虚函数同名覆盖原则：只有当父类和子类虚函数声明完全一致时，才会覆盖父类的虚函数（包含限定符），否则只是重载同名虚函数

*/
