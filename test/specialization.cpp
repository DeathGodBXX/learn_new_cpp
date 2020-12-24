#include <iostream>

template <typename T>
class Base
{
public:
    static const int baseid = 1;
};

template <>
class Base<float>
{
public:
    static const int basefloatid = 0;
};

int main()
{
    std::cout << Base<int>::baseid << std::endl;
    std::cout << Base<float>::basefloatid << std::endl;
    // std::cout << Base<float>::baseid << std::endl;
    // std::cout << Base<int>::basefloatid << std::endl;
}