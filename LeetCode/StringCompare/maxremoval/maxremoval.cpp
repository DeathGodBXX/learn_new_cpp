/*
给定一个removal数组，p是s的子序列，最多删除removal的前k个下标，s仍然为p的子序列
*/
#include "header.h"
class Solution
{
public:
    int maximumRemovals(string s, string p, vector<int> &removable)
    {
        int n = removable.size();
        for (int i = 0; i < n; i++)
        {
            s[removable[i]] = ' ';
            if (!contains(s, p))
                return i;
        }
        return n;
    }

    bool contains(string s, string p)
    { //改进字符串匹配算法。
        if (p.size() == 0)
            return true;
        auto itr = s.begin();

        for (char ch : p)
        {
            while (*itr != ch && itr != s.end())
                ++itr; //*itr=ch跳出循环,或者itr=s.end()
            if (itr == s.end())
                return false; //走到结尾都没有匹配到ch，说明匹配不到，返回false
            ++itr;            //匹配到了之后，指针后移一步
        }

        return true;
    }
};