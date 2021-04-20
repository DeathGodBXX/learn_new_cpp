#include <vector>
using std::vector;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    { //凑零钱1是最少硬币数
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        // for(int &coin:coins){ //以当前硬币结尾，组合出，
        //     for(int i=amount;i>=1;i--){
        //         int j=i-coin;
        //         while(j>=0) { //每一次耗尽当前coin，再使用别的coin;其实这一步在第coin.index前层已经重复遍历了
        //             dp[i] += dp[j];
        //             j-= coin;
        //         }
        //     }
        // }
        for (int &coin : coins)
        { //避免了不必要的计算，加快运行速度
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
