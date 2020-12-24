// rob the most money

#include <iostream>
#include <vector>
//#include <cmath>

int robbing(const std::vector<int> &arr);

int main()
{
    std::vector<int> arr = {2, 3, 9, 7}; //坐标【0，1，2，3，4】
    std::cout << robbing(arr) << std::endl;
    return 0;
}

int robbing(const std::vector<int> &arr)
{
    if (arr.empty())
        return 0;
    std::vector<int> dp; //坐标【0，1，2，3，4，5】
    // dp[0] = 0;
    // dp[1] = arr[0]; 初始时刻，dp是空指针，capacity=size=0;push_back可以不断的申请内存
    dp.push_back(0);
    dp.push_back(arr[0]);
    int len = arr.size();
    for (int i = 2; i <= len; i++)
        dp.push_back(std::max(dp[i - 1], dp[i - 2] + arr[i - 1]));
    return dp[len];
}
