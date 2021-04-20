//变参模板调用优先级低于定参模板;变参模板类的定义与实例化
#include <iostream>
#include <vector>
#include <string>
#include <map>

template <typename T, typename... Ts>
void printf1(T t, Ts... ts)
{
    std::cout << t << "Ts调用" << std::endl;
}

//如果没有这个模板，printf1(3)会调用第一个模板，否则调用此模板
template <typename T>
void printf1(T t)
{
    std::cout << t << std::endl;
}

template <typename... Ts>
class Magic
{
public:
    void show() { std::cout << "Magic" << std::endl; }
};

//加不加class都不影响，这里加了，是为了标注Magic是个类，nothing和magic分别是实例化的对象
class Magic<> nothing;
class Magic<int,
            std::vector<int>,
            std::map<std::string, int>>
    magic;

int main()
{
    printf1(3);
    printf1(3, 4);
    nothing.show();
    magic.show();
}