//递归模板函数解包变长参数 c++11
#include <iostream>

//必须包含最后一次执行结果，根据优先级，最后一次必然执行定长参数模板函数
//相当于最后一次执行了一次单参数的printf1
template <typename TO>
void printf1(TO value)
{
    std::cout << value << std::endl;
}

//相当于最后一次执行了无参数的printf1
// template <typename... Ts>
// void printf1(Ts... ts) {}

//上诉两个模板只要存在一个，就能通过编译
template <typename T, typename... Ts>
void printf1(T value, Ts... ts)
{
    std::cout << value << std::endl;
    if (sizeof...(ts) > 0)
        printf1(ts...);
}

int main()
{
    printf1(1, 2.0, "string", "char");
}

//无法直接解包变量ts
// template <typename... Ts>
// void printf1(Ts... ts)
// {
// std::cout << ts... << std::endl; 不能直接处理包装后的参数 ts 无法解包
// }
