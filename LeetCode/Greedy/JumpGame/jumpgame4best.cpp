#include "header.h"
class Solution
{
public:
    int maxJumps(vector<int> &arr, int d)
    {
        int n = arr.size();
        dp.resize(n, -1); //初始化dp数组
        for (int i = 0; i < n; i++)
            dfs(arr, i, d, n);
        return *max_element(dp.begin(), dp.end());
    }

    void dfs(vector<int> &arr, int id, int d, int n)
    {   //动态规划的过程，计算当前位置的最值，被半径为d的区间笼罩。每次都是以此类推。
        //记忆化减少每次搜寻次数。
        if (dp[id] != -1)
            return;
        dp[id] = 1;
        for (int i = id - 1; i >= 0 && i >= id - d && arr[i] < arr[id]; i--)
        { //回退
            dfs(arr, i, d, n);
            dp[id] = max(dp[id], dp[i] + 1);
        }
        for (int i = id + 1; i < n && i <= id + d && arr[i] < arr[id]; i++)
        { //前进
            dfs(arr, i, d, n);
            dp[id] = max(dp[id], dp[i] + 1);
        }
        return;
    }

private:
    vector<int> dp;
};