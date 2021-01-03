//凑零钱
#include <iostream>
#include <vector>
#include <cmath>

int coinchange(std::vector<int> &coins, int amount);

int main()
{
    std::vector<int> dp = {1, 3, 4, 5};
    int amount;
    std::cout << "请输入目标金额:";
    std::cin >> amount;
    std::cout << coinchange(dp, amount) << std::endl;
}

int coinchange(std::vector<int> &coins, int amount)
{
    //定义amount+1数组大小，存储每个子问题所需硬币数。
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i < dp.size(); i++)
    {
        for (int coin : coins)
        {
            if (i - coin < 0)
                continue;
            //分解当前问题为每个子问题最优值
            dp[i] = std::min(dp[i], 1 + dp[i - coin]);
        }
    }
    return (dp[amount] == amount + 1) ? -1 : dp[amount];
}

//动态规划，求出每个子问题的最小值，再求出amout所需问题最少硬币数
//不同于递归算法从顶部求解，这里是从根部求解，算法复杂度O（kn)

//注意一点：不能顺序拿出硬币面值大的，在依次取出，反例：要求从{1,3,4,5}中凑出7最少的硬币数 {5,1,1},{4,3}.
