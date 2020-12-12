//移动语义，防止数据拷贝的浪费时间空间的操作
#include <iostream>

class A
{
public:
    int *pointer;
    A() : pointer(new int(3))
    {
        std::cout << "default" << std::endl;
    };                                     //默认构造函数
    A(A &a) : pointer(new int(*a.pointer)) //拷贝构造函数(无意义的析构，复制)
    {
        a.pointer = nullptr;
        std::cout << "拷贝" << std::endl;
    }

    A(A &&a) : pointer(a.pointer) //移动构造函数
    {
        a.pointer = nullptr;
        std::cout << "移动" << std::endl;
    }
    ~A()
    {
        delete pointer;
        std::cout << "析构" << std::endl;
    }
};

A test(bool bl) //函数return之后，产生将亡值a or b
{
    A a, b;
    if (bl)
        return a; //等价于 static_cast<A&&>(a)
    else
        return b; //等价于 static_cast<A&&>(b)
}

int main()
{
    A obj = test(false);
    /*调用test之后，产生将亡值b,再调用移动构造函数A(A&&)，延长b的声明周期，
    将指针pointer传递给obj,将亡值指针赋值为nullptr,表达式结束后，再析构b,a
    (a,b都是将亡值，表达式结束后，一起析构)*/
    std::cout << "obj:" << std::endl;
    std::cout << obj.pointer << std::endl;
    std::cout << *obj.pointer << std::endl;
}

//输出结果:
/*
    default
    default
    移动  
    析构
    析构
    obj:
     0x....
     3
     析构
    
*/