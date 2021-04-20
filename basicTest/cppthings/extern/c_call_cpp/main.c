#include <stdio.h>
extern int sub(int, int); //引入sub的声明，不能引入sub.h,否则回报错extern "C"
// #include "sub.h"
int main()
{
    printf("%d\n", sub(2, 1));
}

/*
操作：
clang++ sub.cpp -o sub.o -std=c++2a //生成可执行文件
clang main.o sub.o -o main.o -std=c17 //链接sub后生成的可执行文件
*/