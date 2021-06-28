/*hashmap形式存储待删除的节点，由于对于hashset频繁地删除插入操作，导致效率低下*/
#include "header.h"
class Solution
{
public:
    int maximumRemovals(string s, string p, vector<int> &removable)
    {
        int n = s.size();
        if (p.size() == 0)
            return n;

        unordered_set<int> removed;
        int head = 0, tail = removable.size() - 1, half = (head + tail) / 2;
        for (int i = head; i <= half; i++)
            removed.emplace(removable[i]);
        while (head <= tail)
        {
            if (!checkIsSequence(s, p, removed))
            {
                //不是子序列，取前半段操作，擦除set中的之前设置的后半段的值，相当于已经为后续前半段设值
                if (head == tail)
                    return head; //head等于tail时，再需要判断当前的head是否删除
                tail = half;
                half = (head + tail) / 2;
                for (int i = half + 1; i <= tail; i++)
                    removed.erase(removable[i]);
            }
            else
            {
                //是子序列，再为后半段设值，只需为后段的一半赋值
                head = half + 1;
                half = (head + tail) / 2;
                for (int i = head; i <= half; i++)
                    removed.emplace(removable[i]);
            }
        }
        return head;
    }

    bool checkIsSequence(string &s, string &p, unordered_set<int> &removed)
    {
        int n = s.size();
        int i = 0;
        auto end = removed.end();
        for (char ch : p)
        {
            while (i < n && ((removed.find(i) != end) || (s[i] != ch)))
                //不满足remvoed.find(i)!=end,就是说remvoed.find(i)==end，此时下标未被删除
                i++;
            if (i >= n)
                return false;
            i++;
        }
        return true;
    }
};