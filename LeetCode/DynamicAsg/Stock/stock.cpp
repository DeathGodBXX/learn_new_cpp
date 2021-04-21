//只完成一笔交易获得的最大利润
//第一种方法:minvalue存储已购买的状态，maxprofit表示已售出，获得的最大利润
//同理，第二种方法记录两种状态
//1.buy,可能来自于上一次的buy，或者利润最大(负利润最小化)
//2.sell,可能来自于上一次的sell,或者上一次的buy和本次的卖出

#include <vector>
#include <algorithm>
#include <tuple>
using std::max;
using std::min;
using std::vector;

class Solution
{
public:
    // int maxProfit(vector<int> &prices)
    // {
    //     int n = prices.size();
    //     if (n == 0 || n == 1)
    //         return 0;
    //     int maxprofit = 0, minvalue = prices[0];
    //     for (int &price : prices)
    //     {
    //         maxprofit = max(maxprofit, price - minvalue);
    //         minvalue = min(minvalue, price);
    //     }
    //     return maxprofit;
    // }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0 || n == 1)
            return 0;
        int buy = -prices[0], sell = 0;
        for (int price : prices)
        {
            // std::tie(buy, sell) = std::make_tuple(
            //     max(buy, -price),
            //     max(sell, buy + price));
            //也可以不使用tie解包和make_tuple拆包，因为上一次的buy，如果先被本次的buy修改也无所谓，因为-price+price==0
            buy = max(buy, -price);
            sell = max(sell, buy + price);
        }
        return sell;
    }
};