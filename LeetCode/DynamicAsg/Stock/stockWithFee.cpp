//每次股票交易带收一定的手续费，可以不限次数进行交易
//状态只有两种，可以对比不带手续费交易的情况，同样也是分为两种
//1.当前持有一支股票，收益额(可能来源于上一次持有的股票--第一种状态，或者上一次未持有股票，现在购买一支股票--第二种状态)
//2.当前未持有股票，收益额(可能来源于上一次未持有股票的情况--第二种状态，或者上一次持有一支股票，现在刚好卖出--第二种状态)

#include <algorithm>
#include <vector>
#include <tuple>
using std::max;
using std::vector;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        if (n == 0 || n == 1)
            return 0;
        int buy = -prices[0] - fee, sell = 0;
        for (int i = 0; i < n; i++)
        {
            std::tie(buy, sell) = std::make_tuple(
                max(buy, sell - prices[i] - fee),
                max(sell, buy + prices[i]));
        }
        return sell;
    }
};