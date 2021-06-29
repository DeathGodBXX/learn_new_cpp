/*1899. 合并若干三元组以形成目标三元组*/
#include "header.h"
class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        int fir, sec, thi, t0 = target[0], t1 = target[1], t2 = target[2]; //重复地执行operator[]
        fir = sec = thi = 0;
        for (vector<int> &vec : triplets)
        { //使用引用减少不必要的临时vector的生成
            if (vec[0] > t0 || vec[1] > t1 || vec[2] > t2)
                continue;
            fir = max(fir, vec[0]);
            sec = max(sec, vec[1]);
            thi = max(thi, vec[2]);
        }
        if (fir == t0 && sec == t1 && thi == t2)
            return true;
        return false;
    }
};