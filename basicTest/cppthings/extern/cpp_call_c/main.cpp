#include <iostream>
extern "C" //使用外部c文件(clang++ main.cpp add.o -o main.o -std=c++2a链接生效) 函数声明
{
#include "add.h"
}

int main()
{
    std::cout << add(1, 2) << std::endl;
}

/*
操作：
clang -c add.c -o add.o -std=c17  //生成机器码文件
clang++ main.cpp add.o -o main.o -std=c++2a //生成可执行文件
*/

/*
不同文件的作用:
add.h 包含函数声明，可以被c,cpp调用，(相当于c,cpp函数外部的函数声明)，将c,cpp连接的纽带
add.c 定义add函数，可以包含add.h，也可以不包含
add.cpp 定义入口函数main，必须包含函数声明add.h,而且必须把add.c的机器码文件链接进去，
(相当于添加add函数定义),使用extern "C",搜索函数符号表，_addii or _add
*/

/*
注意事项:
1.编写add.c，添不添加add.h头文件都可行，一般最好添加
2.编写add.h，头文件函数声明
3.编写main.cpp,利用extern和include引入函数声明，且搜寻同一个函数不同符号对照表
*/