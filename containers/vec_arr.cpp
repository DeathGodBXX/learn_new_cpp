//vector适用于不定长数组，array适用于定长数组，使用标准库，可以使用他们自带的方法
#include <iostream>
#include <vector>
#include <string>
#include <array>
// #include <algorithm>

void foo(int *p, int len)
{
    return;
}
int main()
{
    //std::vector<std::string>
    std::vector<std::string> v;
    v.push_back("小明");
    v.push_back("小白");
    std::cout << "v.size=" << v.size() << std::endl;
    std::cout << "v.capacity=" << v.capacity() << std::endl;

    v.push_back("小黄");
    v.push_back("小李");
    std::cout << "v.size=" << v.size() << std::endl;
    std::cout << "v.capacity=" << v.capacity() << std::endl;

    v.clear();
    // v.shrink_to_fit(); 可以不用手动释放v，利用valgrind检测到已经被释放了
    std::cout << "v.size=" << v.size() << std::endl;
    std::cout << "v.capacity=" << v.capacity() << std::endl;

    //std::vector<int *>
    std::vector<int *> vv;
    int *a = new int(10), *b = new int(11);
    vv.push_back(a);
    vv.push_back(b);
    std::cout << "vv.size=" << vv.size() << std::endl;
    std::cout << "vv.capacity=" << vv.capacity() << std::endl;

    vv.clear();
    delete a;
    delete b;

    vv.shrink_to_fit();

    //std::array<int,4>
    constexpr int len = 10;
    std::array<int, len> arr = {1, 10, 2, 3, 7, 4, 3, 4};
    std::cout << "arr.size=" << arr.size() << "\tarr.empty=" << arr.empty() << std::endl;

    std::sort(arr.begin(), arr.end(), [](int a, int b) {
        return a > b;
    });
    for (const int &a : arr)
    {
        std::cout << a << "\t";
    }
    std::cout << std::endl
              << arr.data() << std::endl
              << &arr[0] << std::endl;

    foo(arr.data(), arr.size());
    foo(&arr[0], arr.size());
}