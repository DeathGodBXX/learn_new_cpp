//using # for  define
#include <iostream>
#include <string>
#define exp(s) std::cout << s << std::endl;
#define exp1(s) std::cout << #s << std::endl;
#define exp2(s) #s;

int main()
{
    exp("bas");
    exp1(bas bass);
    std::string str = exp2(bake make mark);
    std::cout << str << "\t" << str.size() << std::endl;
}