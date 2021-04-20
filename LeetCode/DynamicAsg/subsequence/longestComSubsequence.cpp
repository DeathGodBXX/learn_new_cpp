//最长公共子序列，比较两个字符串，找出最长公共子序列。
#include <string>
#include <algorithm>
using std::max;
using std::string;
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        //双指针
        int s1 = text1.size(), s2 = text2.size();
        int dp[s1 + 1][s2 + 1];
        //初始化空串，匹配到的字符串
        for (int i = 0; i <= s1; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= s2; j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= s1; i++)
            for (int j = 1; j <= s2; j++)
            {
                //字符串从0开始的，但是i,j指的是字符串的长度，i=j=0,表示空串；
                if (text1[i - 1] != text2[j - 1])
                {
                    // int idx = text2.find_last_of(text1[i]);需要判断idx不越界，可能为-1，但是-1-1=-2，越界了。
                    // dp[i][j]=max(dp[i-1][idx-1]+1,dp[i-1][j]);
                    //丢弃第i个或者第j个字符
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
                else
                {
                    //第i和第j个字符虽然相等，可以匹配，也可以不匹配；
                    //匹配自然不用说了，若是强行不匹配，假如让第i个和text2[:j]匹配，还不如匹配的子序列长，同理让第j个；
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
        return dp[s1][s2];
        //单指针即可,固定text1,给定text2一个头指针，移动头指针，数学归纳，大的情形都归结到小的情况;但是子序列的长度会改变，拿最简单的情况，2个字符text2,就难以比较。
    }
};