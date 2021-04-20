//for循环的简化遍历
#include <iostream>
#include <vector>
#include <algorithm>
//c++2a之后不用引入algorithm，但是之前的版本都要引入algorithm(c++17) std::find函数的使用需要这个库文件

int main()
{
    std::vector<int> vec = {1, 2, 3, 4};
    if (auto ele = std::find(vec.begin(), vec.end(), 3); ele != vec.end()) //ele is pointer
    {
        *ele = 4;
    }
    for (auto itr : vec) //read only
    {
        std::cout << itr << "\t";
    }
    std::cout << std::endl;

    for (auto &itr : vec) //writable
    {                     //使用itr的引用
        itr += 1;
    }
    for (auto itr : vec) //read only
    {
        std::cout << itr << "\t";
    }
    std::cout << std::endl;
}