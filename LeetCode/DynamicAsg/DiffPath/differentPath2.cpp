//不同路径2，跟1一样，只不过带有障碍物

#include <vector>
using std::vector;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        //动态规划
        int m = obstacleGrid.size(), n = obstacleGrid.at(0).size();
        vector<int> ans(n, 0);
        ans[0] = 1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                //数组初始化为0，ans[0]=1,如果第一个元素为障碍，ans[0]=0,那么后续全为0；
                //第一行ans[j]=ans[j]+ans[j-1]=0+ans[j-1]，只要出现一个为0，后续全为0;
                //第一列的元素只被第一个if控制，只要一次修改为0，一直都是0
                if (obstacleGrid[i][j] == 1)
                {
                    ans[j] = 0;
                    continue;
                }
                if (j >= 1)
                    ans[j] += ans[j - 1];
            }
        return ans.back();
    }
};
