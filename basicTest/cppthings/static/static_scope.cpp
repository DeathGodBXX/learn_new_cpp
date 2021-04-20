//定义对象调用构造函数，对象作用域结束调用析构函数
#include <iostream>
using std::cout;
using std::endl;

class Apple
{
public:
    Apple()
    {
        cout << "constructor" << endl;
    }
    ~Apple()
    {
        cout << "destructor" << endl;
    }
};

int main()
{
    int x = 1;
    if (x)
        Apple apl;
    if (x)
        static Apple apl2;
    cout << "End" << endl;
}

/*
1
constructor
destructor
constructor
End
destructor
*/