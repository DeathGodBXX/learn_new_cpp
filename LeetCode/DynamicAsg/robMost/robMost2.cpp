#include <vector>
#include <algorithm>
#include <array>
using std::array;
using std::max;
using std::vector;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        //没有类似于go的数组切片操作;
        //隔离一间房，最后一间或者第一间
        //3间房以上隔离
        return max(robMost(nums, 1, n), robMost(nums, 0, n - 1));
    }

    int robMost(vector<int> &nums, int first, int last)
    { //数组开始索引first，结束索引last;
        if (last - first + 1 == 2)
            return max(nums[first], nums[last]);
        array<int, 3> dp;
        dp[0] = 0;
        dp[1] = nums[first];
        for (int i = first + 1; i < last; i++)
        {
            dp[2] = max(dp[1], dp[0] + nums[i]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }
};