//初始化列表展开
#include <iostream>
#include <initializer_list>
#include <vector>

template <typename T, typename... Ts>
void printf1(T value, Ts... ts)
{
    std::cout << value << std::endl;
    (void)std::initializer_list<T>{
        ([&ts] { std::cout << ts << std::endl; }(), value)...};
    //注意初始化列表的类型T=decltype(1)=int
    /* 通过初始化列表，(lambda 表达式, value)... 将会被展开。
    由于逗号表达式的出现，首先会执行前面的 lambda 表达式，完成参数的输出。 
    为了避免编译器警告，我们可以将 std::initializer_list 显式的转为 void。
    注意匿名函数无返回值，所以T=decltype(value)=int
    */
}

class Test
{
public:
    int x = 1;
    float y = 2;
};

int main()
{
    // std::vector<int> vec = {1, 2, 3, 4};
    printf1(1, 2, "string", "char", 2 == 42);

    Test test;
    // std::cout << test << std::endl; 想要输出test，需要运算符重载
}

/*
事实上，有时候我们虽然使用了变参模板，却不一定需要对参数做逐个遍历，
我们可以利用 std::bind 及完美转发等特性实现对函数和参数的绑定，从而达到成功调用的目的。
*/