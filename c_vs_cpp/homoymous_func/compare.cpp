// #include <stdio.h>
#include <iostream>

int Add(int a, int b)
{
    return a + b;
}

float Add(float a, float b)
{
    return a + b;
}
int main()
{

    Add(10, 20);
    Add(20.0f, 30.0f);
    return 0;
}