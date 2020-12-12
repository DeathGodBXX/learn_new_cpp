#include <iostream>
#include <string>
//复制
void lookup_1(std::string str)
{
    str = "ok";
}

//引用
//引用而不是复制；不用再将string地址赋值给指针来修改值
//引用类型是std::string,返回的是string类型的引用
//rust处理方式是所有权转移到函数中str,最后再将所有权传递给返回值
//如果不传递引用，在函数中只是赋值而已
void lookup_2(std::string &str)
{
    str = "ok";
}
int main()
{
    std::string str_copy = "hello everyone!!!";
    std::cout << "执行lookup_1前:" << str_copy;
    lookup_1(str_copy);
    std::cout << ", 执行lookup_1之后:" << str_copy << std::endl;

    std::string str = "hello everyone!!";
    std::cout << "执行lookup_2之前:" << str;
    lookup_2(str);
    std::cout << ", 执行lookup_2之后:" << str << std::endl;
}
