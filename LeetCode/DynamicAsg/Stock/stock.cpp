//只完成一笔交易获得的最大利润
//minvalue存储已购买的状态，maxprofit表示已售出，获得的最大利润

#include <vector>
#include <algorithm>
using std::max;
using std::min;
using std::vector;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0 || n == 1)
            return 0;
        int maxprofit = 0, minvalue = prices[0];
        for (int &price : prices)
        {
            maxprofit = max(maxprofit, price - minvalue);
            minvalue = min(minvalue, price);
        }
        return maxprofit;
    }
};