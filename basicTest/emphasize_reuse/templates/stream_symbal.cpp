//>>这种流操作符，能够在定义magic时使用,但是不建议
#include <iostream>
#include <vector>

template <bool T>
class Magic
{
public:
    bool value = T;
};

int main()
{
    std::vector<Magic<(1 > 2)>> magic;
    for (auto v : magic)
        std::cout << v.value << std::endl;
    std::cout << magic.capacity() << std::endl; //cap=0;
}