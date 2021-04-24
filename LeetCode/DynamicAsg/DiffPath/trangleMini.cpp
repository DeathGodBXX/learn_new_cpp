//从三角形的顶点走到最底层的路径长度，只能向右和向下，也就说i只能向i+1,i移动

#include <vector>
#include <algorithm>
using std::min;
using std::vector;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size(), n = triangle.at(m - 1).size();
        if (n == 1)
            return triangle[0][0];
        vector<int> ans(n, 0);
        ans[0] = triangle[0][0];
        for (int i = 1; i < m; i++)
        {
            //必须要从数组尾部向前部，修改数值。因为从后往前不会先修改下标较小的对应的值
            ans[i] = ans[i - 1] + triangle[i][i];
            for (int j = i - 1; j >= 1; j--)
            {
                ans[j] = min(ans[j], ans[j - 1]) + triangle[i][j];
            }
            ans[0] += triangle[i][0];
        }
        return *std::min_element(ans.begin(), ans.end()); //cpp中利用iterator迭代器(指针)移动，获取最小值
    }
};