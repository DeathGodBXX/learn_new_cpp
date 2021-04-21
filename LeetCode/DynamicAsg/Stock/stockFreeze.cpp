//卖出之后存在冷冻期，尽可能多的完成交易，获取最大利润
//当前状态分为三种：(购买时负收益，买出是正收益，利润就是正负收益的平衡下的最大值)
//1.当前拥有股票，获取的最大利益(可能来自于前一天所拥有的股票--第一状态转换，或者前一天没有股票且当前可以正常购买股票--第三种状态转化而来)
//2.当前不拥有股票，且后一天刚好处于冷冻期，获取的最大收益(现在必须卖出前一天的买入的股票--第一种状态转换)
//3.当前不拥有股票，且后一天可以正常购买股票，获取到的最大收益(现在正好处于前一天操作之后的冷冻期--第二种状态转换，或者前一天没进行任何操作--第三种状态转换)

#include <vector>
#include <tuple>
#include <algorithm>

using std::make_tuple;
using std::max;
using std::tie;
using std::vector;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        int n = prices.size();
        //owned表示当前已经拥有一份股票
        //freezed表示当前没有购买一份股票，接下来一天会进入冷冻期
        //normal表示当前没有购买一份股票，接下来可以正常交易
        int owned = -prices[0], freezed = 0, normal = 0;
        for (int i = 1; i < n; i++)
        {
            tie(owned, freezed, normal) = make_tuple(
                max(owned, normal - prices[i]), //正常交易情况下，当前购买股票；或者前一天购买的股票
                owned + prices[i],              //必须当前售出，前天拥有一份股票，才会进入冷冻期
                max(freezed, normal)            //不拥有股票，可能是当前处于冷冻期，或者前一天正常交易，但是没有购买股票
            );
        }
        return max(freezed, normal);
    }
};