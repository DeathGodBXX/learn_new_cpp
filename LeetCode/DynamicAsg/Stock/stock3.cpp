//最多完成2笔交易，获得最大利润
//对比只完成1笔交易，当时只是存在已购买，已售出；
//现在完成两笔交易，存在4中状态--购买1，售出1，购买2，售出2

#include <algorithm>
#include <vector>
using std::max;
using std::vector;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; i++)
        {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return max(sell1, sell2);
    }
};