//auto用来推导变量类型，decltype可以用来推导表达式类型
#include <iostream>
#include <vector>
#include <initializer_list>

class Foo
{
public:
    std::vector<int> vec;
    Foo(std::initializer_list<int> list)
    {
        for (auto ele = list.begin(); ele != list.end(); ele++)
        {
            vec.push_back(*ele);
        }
    }
    void show()
    {
        for (auto ele = vec.begin(); ele != vec.end(); ele++)
        {
            std::cout << *ele << std::endl;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Foo foo{1, 2, 3, 4, 5};
    foo.show();

    auto x = 1;
    auto y = 2;
    decltype(x + y) z;
    if (std::is_same<decltype(x), int>::value)
        std::cout << "type x = int" << std::endl;

    if (std::is_same<decltype(x), float>::value)
        std::cout << "type x = float" << std::endl;

    if (std::is_same<decltype(x), decltype(z)>::value)
        std::cout << "type x = type z" << std::endl;
}