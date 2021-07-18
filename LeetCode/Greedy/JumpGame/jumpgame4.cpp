#include "header.h"
class Solution
{
public:
    int maxJumps(vector<int> &arr, int d)
    {
        int n = arr.size();
        dp.resize(n, -1);
        for (int i = 0; i < n; i++)
            if (dp[i] == -1)
                dfs(arr, i, d, n);
        return *max_element(dp.begin(), dp.end());
    }

    void dfs(vector<int> &arr, int id, int d, int n)
    {
        if (arr[id] <= arr[max(0, id - 1)] && arr[id] <= arr[min(n - 1, id + 1)])
        {
            //当前id的左右两个邻居都比arr[id]值大，那么dp[id]只可能是1,特殊情况提前返回
            dp[id] = 1;
            return;
        }
        int end = min(id + d, n - 1), max_value = 0;
        for (int i = id + 1; i <= end; i++)
        {
            //1.过滤掉比当前值大的节点，2.定义未定义的值，只有比arr[id]小的值才会影响当前节点的值。
            if (arr[i] >= arr[id])
                break;
            if (dp[i] == -1)
                dfs(arr, i, d, n); //计算右侧的dp[i],这样循环最终的左侧的dp[i]都是先完成的，所以不用遍历左侧计算dp[i],也就是最外层的for循环都从id+的项开始的，不需要从id-开始
            max_value = max(max_value, dp[i]);
        }

        int m = max(0, id - d);
        for (int i = id - 1; i >= m; i--)
            //从当前节点开始，向左查找出最小的，一旦发现dp[i]>=arr[id],循环结束
            //对应于发现无法跳跃的gap
            if (arr[i] < arr[id])
                max_value = max(max_value, dp[i]);
            else
                break;

        dp[id] = max_value + 1;
        return;
    }

private:
    vector<int> dp;
};