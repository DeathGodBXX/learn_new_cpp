//非类型模板参数，也就是模板参数中能含有int,float,string等的字面值
#include <iostream>
#include <vector>

template <typename T, int num>
class Data
{
public:
    T x;
    void printf1()
    {
        std::cout << "num=" << num << std::endl;
    }
};
int main()
{
    Data<int, 10> data;
    data.x = 100;
}