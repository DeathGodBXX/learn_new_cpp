#include <algorithm>
#include <vector>
using std::vector;

int lengthOfLIS1(vector<int> &nums)
{
    vector<int> dp(int(nums.size()), 0);
    dp.push_back(1);
    dp.front();
    for (int i = 1; i < nums.size(); i++)
    {
        int largest = 1;
        for (int j = 0; j < i; j++)
            if (nums[j] < nums[i])
                largest = std::max(largest, dp.at(j) + 1);
        dp.push_back(largest);
    }
    return *std::max_element(dp.begin(), dp.end());
}

int lengthOfLIS(vector<int> &nums)
{
    vector<int> dp;
    for (int i = 0; i < nums.size(); i++)
    {
        //二分查找位置
        int left = 0, right = dp.size();
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (dp[mid] < nums[i])
                left = mid + 1;
            else
                right = mid;
        }
        if (left == dp.size())
            dp.push_back(nums[i]); //有扩容操作
        else
            dp[left] = nums[i];
    }
    return dp.size();
}
