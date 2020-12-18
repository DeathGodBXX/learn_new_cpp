#include <iostream>

int main()
{
    volatile const int a = 20;
    //a是const，虽然程序内不能修改，但是外部接口可以修改，比如gdb调试
    //如果不加volatile,gdb调试修改a的值，cout的a的值没有发生改变(仍然从寄存器取值)，但是打印出来的信息确是修改了(内存加载)
    //添加volatile,即使gdb修改了a的值，也能观测到
    for (int i = 0; i < 10; i++)
    {
        std::cout << a << std::endl;
    }
}

/*
rsp:0x7fffffffdb70
rbp:0x7fffffffdb80
i: 0x7fffffffdb74   -0xc(%rbp)  80-0c=74    //通过栈基地址加偏移量，可以访问i的值(内存内的值)
a: 0x7fffffffdb78   -0x8(%rbp)  80-08=78   //注意是16进制

*/

/*
用到的调试命令：
clang++ -g volatile.cpp -o main.o -std=c++2a
gdb main.o
(gdb) b volatile.cpp:11
(gdb) start
(gdb) c
(gdb) print a(or &a,&i,i)
(gdb) set var a=100
(gdb) print a
(gdb) c    
对比print a和 c 命令下a的输出值

*/

/*
volitail作用：
告诉编译器此变量不稳定，不进行编译优化，每次读写操作都是基于内存而不是寄存器
只读的状态寄存器，中断服务子程序，线程同步
(编译系统未知的因素修改，操作系统，硬件，线程)
*/