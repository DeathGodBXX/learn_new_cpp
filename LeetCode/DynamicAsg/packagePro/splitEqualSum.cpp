#include <vector>;
using std::vector;
class Solution
{
public:
    // bool canPartition(vector<int>& nums) {
    //     int sum=0;
    //     for(int &i:nums) sum += i;
    //     if(sum%2==1) return false;
    //     sum = sum/2;
    //     int n=nums.size();
    //     vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
    //     for(int i=1;i<n+1;i++) dp[i][0]=true; //初始化,当sum=0时，认为成功；
    //     for(int i=1;i<n+1;i++){ //处理当前i个物品
    //         for(int j=1;j<=sum;j++){ //需处理的和
    //             if(j-nums[i-1]<0) dp[i][j]=dp[i-1][j]; //装不下
    //             else dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]]; //装得下，但是可装可不装
    //         }
    //     }
    //     return dp[n][sum];

    // }
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int &i : nums)
            sum += i;
        if (sum % 2 == 1)
            return false;
        sum = sum / 2;
        int n = nums.size();
        vector<bool> dp(sum + 1, false); //每次计算都只是依赖上一次计算，而且最终只是需要计算dp[sum]，所以可以简化成为1为vector;
        dp[0] = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = sum; j >= 0; j--)
            { //依赖于第i-1次的计算的dp[j-nums[i]],而不是本i次计算的dp[j-nums[i]]
                if (j - nums[i] >= 0)
                    dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};