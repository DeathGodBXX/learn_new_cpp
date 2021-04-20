//模板是用来产生类型的，使用typedef为类型定义别名，使用using对模板和函数定义别名，也可以为类型定义别名

#include <iostream>
#include <vector>

template <typename T, typename U>
class MagicType
{
public:
    T dark;
    U magic;
};

//using for class template
template <typename T>
// typedef MagicType<std::vector<T>, std::string> DarkMagicType; typedef不能为模板定义别名
using DarkMgicType = MagicType<std::vector<T>, std::string>;

//using for func template
int show()
{
    return 10;
}
typedef int (*Process)(); //函数指针简化函数的调用
                          //函数指针类型的定义; int(*Process)(int,int);
                          // 声明了一个指向int(int,int)函数指针Process;
                          // 而此处是定义了函数指针的类型；
using NewProcess = int (*)();

//using for typedef
typedef int INT;
using FLOAT = float;

int main()
{
    //using for class template
    //指定class的T，U类型，自动生成默认的构造函数；如果只是模板函数，可以不指定类型，会自动进行推导
    auto x = MagicType<bool, std::string>{false, "string"};
    std::cout << x.dark << "\t" << x.magic << std::endl;

    //只需指定T类型，生成新的构造函数
    auto y = DarkMgicType<int>{{1, 2, 3, 4, 5}, "string"};
    for (auto v : y.dark)
        std::cout << v << "\t";
    std::cout << std::endl
              << y.magic << std::endl;

    //using for func template
    //函数指针类型的定义与调用
    Process ps = show;
    NewProcess ns = show;
    std::cout << show() << std::endl;
    std::cout << ps() << "\t" << (*ps)() << std::endl;
    std::cout << ns() << "\t" << (*ns)() << std::endl;

    //using for typedef
    INT i = 1;
    FLOAT j = 1.0;
}