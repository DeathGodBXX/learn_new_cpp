#include <iostream>
#include <vector>
#include <utility>
#include <string>

int main()
{
    std::string str = "Hello,World!!!";
    std::vector<std::string> vec;
    vec.push_back(str);
    std::cout << "常值引用之后，str：" << str << std::endl;
    //常值引用之后，str：Hello,World!!!
    //push_back(const T&) 拷贝
    vec.push_back(std::move(str));
    std::cout << "右值引用之后，str:" << str << std::endl;
    //右值引用引用之后，str:
    //std::move(str)强制把左值引用转换成右值引用，push_back(const T&&) 移动， 防止了数据拷贝开销
}