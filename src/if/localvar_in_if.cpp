//在if条件语句中定义局部变量；细粒度化变量作用域； switch,for都可以这么干
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4};
    const std::vector<int>::iterator itr = std::find(
        vec.begin(), vec.end(), 2);
    if (itr != vec.end())
    {
        *itr = 3;
    }
    const std::vector<int>::iterator itr2 = std::find(
        vec.begin(), vec.end(), 3);
    if (itr2 != vec.end())
    {
        *itr = 4;
    }
    for (std::vector<int>::iterator ele = vec.begin(); ele != vec.end(); ele++)
    {
        std::cout << *ele << "\t";
    }

    std::cout << std::endl;

    //c++17可以在条件语句里设置局部变量
    std::vector<int> vec1 = {1, 2, 3, 4};
    if (const std::vector<int>::iterator ele = std::find(vec1.begin(), vec1.end(), 2);
        ele != vec1.end())
    {
        *ele = 3;
    }
    if (const std::vector<int>::iterator ele = std::find(vec1.begin(), vec1.end(), 3);
        ele != vec.end())
    {
        *ele = 4;
    }
    for (std::vector<int>::iterator ele = vec1.begin(); ele != vec1.end(); ele++)
    {
        std::cout << *ele << "\t";
    }
    std::cout << std::endl;
}