//引用坍缩规则
#include <iostream>

void reference(int &v)
{
    std::cout << "左值" << std::endl;
}

void reference(int &&v)
{
    std::cout << "右值" << std::endl;
}

template <typename T>
void pass(T &&t)
{
    reference(t);
}
int main()
{
    // int i = 1;
    // int &&j = i; //无法将右值引用绑定到左值上

    std::cout << "传递右值" << std::endl;
    pass(1); //虽然被推导为右值，但是t又是引用，又称为左值；

    std::cout << "传递左值" << std::endl;
    int l = 1;
    pass(l);
}

/*
函数形参类型 	实参参数类型 	推导后函数形参类型
    T& 	        左引用 	            T&
    T& 	        右引用 	            T&
    T&& 	    左引用 	            T&
    T&& 	    右引用 	            T&&
*/

/*
在这份实现中，std::remove_reference 的功能是消除类型中的引用， 而 std::is_lvalue_reference 用于检查类型推导是否正确，
在 std::forward 的第二个实现中 检查了接收到的值确实是一个左值，进而体现了坍缩规则。

当 std::forward 接受左值时，_Tp 被推导为左值，而所以返回值为左值；而当其接受右值时， _Tp 被推导为 右值引用，则基于坍缩规则，
返回值便成为了 && + && 的右值。 可见 std::forward 的原理在于巧妙的利用了模板类型推导中产生的差异。

这时我们能回答这样一个问题：为什么在使用循环语句的过程中，auto&& 是最安全的方式？ 因为当 auto 被推导为不同的左右引用时，与 && 的坍缩组合是完美转发。
*/