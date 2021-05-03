#include "header.h"

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        set<int> set;
        int n = nums.size();
        if (n == 0 || n == 1 || k == 0)
            return false;
        set.insert(nums[0]);
        for (int i = 1; i < n; i++)
        { //利用set的有序性
            //未处理极端用例情形
            if (abs(*set.begin() - nums[i]) <= t || abs(*set.rbegin() - nums[i]) <= t)
                return true;

            for (int j = nums[i] - t; j <= nums[i] + t; j++)
                if (set.find(j) != set.end())
                    return true;

            if (set.size() == k)
                set.erase(nums[i - k]);
            set.insert(nums[i]);
        }
        return false;
    }
};
