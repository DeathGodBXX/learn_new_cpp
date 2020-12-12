//Lambda表达式(匿名函数不能直接使用函数外部变量，必须先捕获)
//[捕获列表](参数列表)mutable(可选)->返回值类型{函数体}
#include <iostream>

//值引用，变量必须可以拷贝；被捕获变量在lambda表达式被创建时拷贝，而非调用时
void lambda_value_capture()
{
    int value = 1;
    auto copy_value = [value] { return value; };
    value = 100;
    std::cout << copy_value() << std::endl;
}

void lambda_quote_capture()
{
    int value = 1;
    auto copy_value = [&value] { return value; };
    value = 100;
    std::cout << copy_value() << std::endl;
}

int main()
{
    lambda_value_capture();
    lambda_quote_capture();
}

/*
tips:

    [] 空捕获列表
    [name1, name2, ...] 捕获一系列变量
    [&] 引用捕获, 让编译器自行推导捕获列表
    [=] 值捕获, 让编译器执行推导引用列表

*/
