#include <vector>
#include <algorithm>
using std::min;
using std::vector;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int &coin : coins)
        { //只使用前coin凑出0...amount的零钱
            for (int i = coin; i <= amount; i++)
            {   //需要凑出的零钱，后面凑出的零钱硬币个数依赖于当前种类零钱选取个数。实际对应的dp数组就是dp[coin对应的index][sum]=硬币个数。必须选取当前硬币种类，否则等价于上一次选取硬币个数。
                // if (i >= coin)
                dp[i] = min(dp[i - coin] + 1, dp[i]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
    // int coinChange(vector<int> &coins, int amount){
    // //定义amount+1数组大小，存储每个子问题所需硬币数。
    //     std::vector<int> dp(amount + 1, amount + 1);
    //     dp[0] = 0;
    //     for (int i = 1; i < dp.size(); i++)
    //     {
    //         for (int coin : coins)
    //         {
    //             if (i - coin < 0)
    //                 continue;
    //             //分解当前问题为每个子问题最优值
    //             dp[i] = std::min(dp[i], 1 + dp[i - coin]);
    //         }
    //     }
    //     return (dp[amount] == amount + 1) ? -1 : dp[amount];
    // }
};