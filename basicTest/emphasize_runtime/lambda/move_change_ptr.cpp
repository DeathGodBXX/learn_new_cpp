//表达式捕获(右值捕获)
#include <iostream>
#include <utility>
#include <memory>

int main()
{
    auto important = std::make_unique<int>(1); //c++14
    std::cout << "important指针存放地址：" << &important
              << "\n,imortant指向地址：" << &(*important)
              << "\n,important指向值" << *important << std::endl;
    auto fn = [v1 = 1, v2 = std::move(important)](int x, int y) {
        std::cout << &v2 << std::endl;
        return v1 + x + y + (*v2);
    };
    std::cout << fn(2, 2) << std::endl;
    std::cout << &important << std::endl;
    //再次取出important指向值会报错，这是因为匿名函数传入imporant右值引用，函数结束后，释放important的指向空间
    //很类似于rust的所有权转移，important指向地址所有权传入函数，函数结束后，作用域里面的变量内存全部释放
    //(此处没有再次发生所有权传出函数)
}