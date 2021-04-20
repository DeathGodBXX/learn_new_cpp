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