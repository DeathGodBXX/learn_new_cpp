/*传参string,copy一份s，用于在副本上修改，后续就不需要恢复s,利用这个小技巧速度能提升到98%,主要内存消耗的在s的复制*/
#include "header.h"
class Solution
{
public:
    int maximumRemovals(string s, string p, vector<int> &removable)
    {
        int n = s.size();
        if (p.size() == 0)
            return n;

        int head = 0, tail = removable.size() - 1, half = (head + tail) / 2;
        while (head <= tail)
        {
            if (!checkIsSequence(s, p, removable, half))
            {
                if (head == tail)
                    return head; //or break
                tail = half;
            }
            else
            {
                head = half + 1;
            }
            half = (head + tail) / 2;
        }
        return head;
    }

    bool checkIsSequence(string s, string &p, vector<int> &removable, int half)
    { //此处修改copy不需要后续修改被调用函数的s，主要内存消耗都在s的复制
        //每次都需要从0开始修改，因为之前修改的都是副本，原有字符串s一直未变
        for (int i = 0; i <= half; i++)
            s[removable[i]] = ' ';

        auto itr = s.begin(), end = s.end();
        for (char ch : p)
        {
            while (itr != end && *itr != ch)
                ++itr;
            if (itr == end)
                return false;
            ++itr;
        }
        return true;
    }
};