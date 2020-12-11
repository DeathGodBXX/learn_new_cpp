//非常值引用的右端只能是左值，(左值引用可为左值，常值引用可以右值)
#include <iostream>
#include <utility>

void increase(int &v)
{
    v++;
}

void foo()
{
    double s = 1;
    // increase(s);
    //新版本可以检测类型不匹配；
    /*由于 int& 不能引用 double 类型的参数，因此必须产生一个临时值来保存 s 的值， 
    从而当 increase() 修改这个临时值时，从而调用完成后 s 本身并没有被修改*/
    std::cout << s << std::endl;
}
int main()
{
    int a = 1;
    int &a1 = a;
    // int &a2 = std::move(1); //不合法，非常量引用不能使用右值
    const int &b = 1; //常量引用可以使用右值(Fortran需要)
}