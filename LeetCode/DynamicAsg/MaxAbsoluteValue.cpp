//Maximum of Absolute Value Expression
//Problem: |arr1[i]-arr1[j]|+|arr2[i]-arr2[j]|+|i-j|?
//close sync with cstdio to accelerate cpp_iostream;
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
#include <limits.h> //define INT_MAX,INT_MIN

using std::max;
using std::min;
using std::pair;
using std::vector;

static const auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution
{
public:
    int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int res = 0;
        vector<pair<int, int>> p = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for (auto it : p)
        {
            int it1 = it.first, it2 = it.second;
            int amax = INT_MIN, amin = INT_MAX;
            for (int i = 0; i < arr1.size(); i++)
            {
                amax = max(amax, arr1[i] + it1 * arr2[i] + it2 * i);
                amin = min(amin, arr1[i] + it1 * arr2[i] + it2 * i);
            }
            res = max(res, amax - amin);
        }
        return res;
    }
};
