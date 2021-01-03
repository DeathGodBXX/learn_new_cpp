// 单调栈

#include <iostream>
#include <array>
#include <stack>

void mono_stack(std::array<int, 10> const &arr, std::array<int, 10> &res);

int main()
{
    std::array<int, 10> arr = {73, 74, 75, 67, 82, 79, 81, 79};
    std::array<int, 10> res = {-1};
    mono_stack(arr, res);
    for (auto i : arr)
        std::cout << i << "\t";
    std::cout << std::endl;
    for (auto i : res)
        std::cout << i << "\t";
    std::cout << std::endl;
}


void mono_stack(std::array<int, 10> const &arr, std::array<int, 10> &res)
{
    std::stack<int> stk;
    for (int i = arr.size() - 1; i >= 0; i--) //遍历数组元素
    {
        while (!stk.empty() && arr[i] >= arr[stk.top()])
        //比较数组当前元素和栈顶索引对应数据大小，如果前元素较大，把栈顶元素弹出，直到栈为空或者当前元素小于栈顶缩影值对应的元素
        {
            stk.pop();
        }
        if (stk.empty())
            res[i] = 0;
        else
            res[i] = stk.top() - i;
        stk.push(i);
        std::cout << stk.top() << std::endl;
    }
}
