//可以完成任意笔交易，获得最大利润
//单调递增区间购买和售出股票

#include <vector>
#include <algorithm>
#include <tuple>
using std::max;
using std::vector;

class Solution
{
public:
    // int maxProfit(vector<int> &prices)
    // {
    //     int n = prices.size();
    //     if (n == 0 || n == 1)
    //         return 0; //边界处理
    //     int min = prices[0], maxProfit = 0;
    //     //尽可能小区段购买股票
    //     for (int i = 1; i < n;)
    //     {
    //         if (prices[i] >= min)
    //         {
    //             while (++i < n && prices[i - 1] < prices[i])
    //                 ; //++i<n防止数组越界
    //             maxProfit = prices[i - 1] - min + maxProfit;
    //             if (i < n)
    //                 min = prices[i];
    //         }
    //         else
    //         {
    //             min = prices[i];
    //             i++;
    //         }
    //     }
    //     return maxProfit;
    // }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0 || n == 1)
            return 0;
        int buy = -prices[0], sell = 0;
        for (int i = 0; i < n; i++)
        {
            std::tie(buy, sell) = std::make_tuple(
                max(buy, sell - prices[i]),
                max(sell, buy + prices[i]));
        }
        return sell;
    }
};