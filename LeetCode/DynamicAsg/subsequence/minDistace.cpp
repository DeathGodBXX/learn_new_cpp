//给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

//示例：

//输入 : "sea", "eat" 输出 : 2 解释 : 第一步将 "sea"变为"ea"，第二步将"eat"变为"ea"

#include <string>
#include <algorithm>
using std::max;
using std::string;
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        return word1.size() + word2.size() - 2 * longestComSubsequence(word1, word2);
    }
    int longestComSubsequence(string word1, string word2)
    {
        int s1 = word1.size(), s2 = word2.size();
        int dp[s1 + 1][s2 + 1];
        for (int i = 0; i < s1 + 1; i++)
            dp[i][0] = 0;
        for (int j = 0; j < s2 + 1; j++)
            dp[0][j] = 0;
        for (int i = 1; i < s1 + 1; i++)
            for (int j = 1; j < s2 + 1; j++)
                if (word1[i - 1] != word2[j - 1])
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j - 1] + 1;
        return dp[s1][s2];
    }
};