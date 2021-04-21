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