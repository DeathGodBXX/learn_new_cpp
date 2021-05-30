#include "../header.h"
class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        map<int, int> mp; //存储第一次出现的数值的最少操作次数。
        int cmp = 0;      //存储一个临时的前一个的操作数，用于对比
        mp.emplace(std::make_pair(arr[0], 0));
        for (int i = 1; i < n; i++)
        {
            int least = cmp + 1; //i-1的最少操作次数+1

            //i+1的最少操作次数跳跃执行
            if (i + 1 < n)
            {
                auto fd = mp.find(arr[i + 1]);
                if (fd != mp.end())
                    least = min(fd->second + 2, least);
            }

            auto fdi = mp.find(arr[i]);
            if (fdi != mp.end())
            {
                least = min(fdi->second + 1, least);
                fdi->second = min(fdi->second, least); //更新存在的最小值
            }
            else
            {
                mp.emplace(std::make_pair(arr[i], least));
            }

            cmp = least; //记录当前所需最小操作数，用于下一次对比
        }
        return cmp;
    }
};