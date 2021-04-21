//最多完成k笔交易获得的最大利润
//对比1笔交易和两笔交易
//现在存在2k中状态--购买1，售出1，购买2，售出2...购买k,售出k

#include <vector>
#include <algorithm>
using std::max;
using std::vector;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        //边界情况
        if (n == 0 || n == 1 || k == 0)
            return 0;
        //偶数下标表示已购买，奇数下标表示已卖出，k个交易，对比stock3.cpp需要vector的长度2k,记录k种状态
        vector<int> vec(2 * k);
        //初始化vector
        for (int j = 0; j < 2 * k; j++)
            vec[j] = (j % 2 == 0) ? -prices[0] : 0;
        for (int i = 1; i < n; i++)
        {
            vec[0] = max(vec[0], -prices[i]);
            for (int j = 1; j < 2 * k; j++)
            {
                int tag = (j % 2 == 0) ? -1 : 1;
                vec[j] = max(vec[j], vec[j - 1] + prices[i] * tag);
            }
        }

        int maxprofit = vec[1];
        for (int j = 3; j < 2 * k; j = j + 2)
        {
            maxprofit = max(maxprofit, vec[j]);
        }
        return maxprofit;
    }
};