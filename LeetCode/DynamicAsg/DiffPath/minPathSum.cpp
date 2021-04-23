#include <vector>
#include <algorithm>
using std::min;
using std::vector;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid.at(0).size();
        vector<int> ans(n, 0);
        for (int i = 0; i < m; i++)
        {
            ans[0] += grid[i][0];
            for (int j = 1; j < n; j++)
            {
                if (i == 0)
                {
                    ans[j] = ans[j - 1] + grid[0][j];
                    continue;
                }
                ans[j] = min(ans[j - 1], ans[j]) + grid[i][j];
            }
        }
        return ans.back();
    }
};