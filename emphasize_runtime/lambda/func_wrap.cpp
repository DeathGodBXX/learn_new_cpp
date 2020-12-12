//函数对象封装器
#include <iostream>
#include <functional>

using foo = void(int);
void func(foo f)
{
    f(1);
}

void add(int x, int y)
{
    std::cout << x + y << std::endl;
}
int main()
{
    //常规操作
    int t = 1;
    auto fn = [](int v) { //空捕获列表才可以当参数传递给func
        std::cout << v << std::endl;
    };
    func(fn);
    fn(1);

    //函数封装
    std::function<void(int, int)> fc = add;
    int x = 10, y = 20;
    std::function<void()> fct = [&] {
        std::cout << x + y << std::endl;
    };
    fc(10, 20);
    fct();
}
//利用函数封装也可以很容易定义代捕获列表的匿名函数