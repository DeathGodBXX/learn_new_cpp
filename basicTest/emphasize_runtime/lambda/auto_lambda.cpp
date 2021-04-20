//auto实现范型lambda，auto类型推断发生在编译器，故而必须一定义就初始化，静态语言；
// 而js,python动态语言的类型推断都是发生在运行时的
#include <iostream>

int main()
{
    auto fn = [](auto x, auto y) {
        return x + y;
    };
    std::cout << fn(1, 2) << std::endl;
    std::cout << fn(1.2, 2) << std::endl;
}