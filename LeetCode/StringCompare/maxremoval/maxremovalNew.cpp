/*同样是解决maxremoval的问题，但是改用一个state数组保存是否删除了当前字符*/
/* 下一步改用hashmap存储当前字符，用于后续查找方便,而不用频繁修改state vector的操作*/

#include "header.h"
class Solution
{
public:
    int maximumRemovals(string s, string p, vector<int> &removable)
    {
        int n = s.size();
        if (p.size() == 0)
            return n;

        vector<int> state(n, 1);
        int head = 0, tail = removable.size() - 1, half = (head + tail) / 2;

        for (; head != tail; half = (head + tail) / 2)
        {
            for (int i = head; i <= half; i++)
                state[removable[i]] = 0;
            if (!checkIsSequence(s, p, state))
            {
                for (int i = head; i <= half; i++)
                    state[removable[i]] = 1;
                tail = half; //tail后退
            }
            else
            {
                head = half + 1; //head前进
            }
        }

        //head==tail时，删除head是否仍然是子序列？
        state[removable[head]] = 0;
        if (!checkIsSequence(s, p, state))
        {
            return head;
        }
        return head + 1;
    }

    bool checkIsSequence(string s, string p, vector<int> &state)
    {
        int n = state.size();
        int i = 0;
        for (char ch : p)
        {
            //加括号，否则会有warning
            while (i < n && ((state[i] == 1 && s[i] != ch) || (state[i] == 0)))
                i++;
            //说明p未匹配完
            if (i >= n)
                return false;
            i++;
        }
        return true;
    }
};