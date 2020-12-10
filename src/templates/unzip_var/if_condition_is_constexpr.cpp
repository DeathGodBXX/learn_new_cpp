//利用constexpr告诉编译器if条件判定局在编译期是常量表达式，这样就不需要最后一次执行结果 c++17
#include <iostream>

template <typename T, typename... Ts>
void printf1(T t, Ts... ts)
{
    std::cout << t << std::endl;
    if constexpr (sizeof...(ts) > 0)
        //c++17 告诉编译器，这在编译器是常量表达式，就不需要最后一次执行结果了
        printf1(ts...);
}
int main()
{
    printf1(1, 2.0, "string", "ok", 2 == 4);
}