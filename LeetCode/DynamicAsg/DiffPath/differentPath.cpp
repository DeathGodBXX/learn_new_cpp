//m*n个格子，从左上方到右下方有多种不同的路径，只能向右走和向下走
#include <vector>
using std::vector;

class Solution
{
public:
    //组合数学
    //1.从(0,0)到(m-1,n-1)，其中路径长度是m+n-2,选取m-1种向下走的方式，组合数(m-1,m+n-2)
    // int uniquePaths(int m, int n) {
    //     long long int ans=1;
    //     for(int x=n,y=1;y<m;x++,y++){
    //         ans = ans*x/y;
    //     }
    //     return ans;
    // }
    //动态规划1
    //2.可以利用数组存储每一步的结果，其中到达ans[i][j]=ans[i-1][j]+ans[i][j-1]种路径。
    // int uniquePaths(int m,int n){
    //     vector<vector<int>> ans(m,vector<int>(n,1));
    //     for(int i=1;i<m;i++)
    //         for(int j=1;j<n;j++){
    //             ans[i][j]=ans[i-1][j]+ans[i][j-1];
    //         }
    //     return ans[m-1][n-1];
    // }
    //改进后的动态规划
    //3.由于每一步都只是依赖于上一层计算结果ans[i-1][j]和本层前一步结果ans[i][j-1]之和
    int uniquePaths(int m, int n)
    {
        vector<int> ans(n, 1);
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
            {
                ans[j] += ans[j - 1];
            }
        return ans.back();
    }
};