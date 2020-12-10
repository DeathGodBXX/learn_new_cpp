//统一将初始化列表绑定到类型上，初始化一致化
#include <iostream>
#include <initializer_list>
#include <vector>

class Foo
{
public:
    int value_a;
    int value_b;
    Foo(int a, int b) : value_a(a), value_b(b){};
};

class MagicFoo
{
public:
    std::vector<int> vec;
    MagicFoo(std::initializer_list<int> list) //统一将初始化列表绑定到类型上，初始化一致化
    {
        for (std::initializer_list<int>::iterator ele = list.begin(); ele != list.end(); ele++)
        {
            vec.push_back(*ele);
        }
    };
    void magic_func(std::initializer_list<int> list) //类对象方法
    {
        for (std::initializer_list<int>::iterator itr = list.begin(); itr != list.end(); ++itr)
        {
            vec.push_back(*itr);
        }
    }
    void magic_show() //类对象方法
    {
        for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
        {
            std::cout << *itr << "\t";
        }
        std::cout << std::endl;
    }
};

int main()
{
    //c++11之前的类对象的初始化
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Foo foo(1, 2);
    for (std::vector<int>::iterator ele = vec.begin(); ele != vec.end(); ele++)
    {
        std::cout << *ele << "\t";
    }
    std::cout << std::endl;
    std::cout << "value_a=" << foo.value_a << ", value_b=" << foo.value_b << std::endl;

    //c++11之后的统一的类对象初始化方式
    MagicFoo magicfoo({
        1,
        2,
    });
    MagicFoo magicfoo1{
        1,
        2,
        3,
    };
    MagicFoo{1, 2, 3}; //初始化匿名变量
    MagicFoo magicfoo2 = {1, 2, 3, 4};
    magicfoo.magic_func({1, 2});
    magicfoo.magic_show();
    magicfoo1.magic_func({1, 2, 3});
    magicfoo1.magic_show();
    magicfoo2.magic_func({1, 2, 3, 4});
    magicfoo2.magic_show();
}