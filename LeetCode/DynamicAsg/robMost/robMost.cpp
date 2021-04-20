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
        // int n=nums.size();
        // if(n==0) return 0;
        // vector<int> dp(n+1,0);
        // dp[1]=nums[0];
        // for(int i=2;i<n+1;i++){
        //     //dp[i]代表偷到当前位置，最多偷到多少金额,i从2开始
        //     //dp[i]最多偷到的金额是前i-1的值和i-2+nums[i-1]的最大值
        //     dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
        // }
        // return dp[n];

        //由于dp只使用i-2，i-1,i这三个，那么可以使用array，数组长度为3,纪录每次的依赖项
        int n = nums.size();
        //容错处理，nums为空或者只有一个元素
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        array<int, 3> dp;
        // dp.fill(0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i < n + 1; i++)
        {
            dp[2] = max(dp[1], dp[0] + nums[i - 1]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }
};