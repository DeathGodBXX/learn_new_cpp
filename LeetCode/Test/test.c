#include <stdio.h>

typedef void (*func)(int);
typedef void(func1)(int);

void none(int a)
{
    printf("%d\n", a);
}

int main()
{
    func a = none;
    none(2);
    a(3);
    func1 *b = none; //必须定义为指针变量，函数指针
    b(4);
}
