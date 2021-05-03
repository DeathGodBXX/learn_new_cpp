#include <vector>
#include <unordered_set>
using std::unordered_set;
using std::vector;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        // unordered_multimap<int,int> mp;
        // int n=nums.size();
        // if(n==0||n==1) return false;
        // for(int i=0;i<n;i++){
        //     if(auto fd=mp.equal_range(nums[i]);fd.first!=fd.second){
        //         for(auto it=fd.first;it!=fd.second;it++){
        //             if(abs(it->second-i)<=k) return true;
        //         }
        //     }
        //     mp.insert({nums[i],i});
        // }
        // return false;
        unordered_set<int> set(k);
        int n = nums.size();
        if (n == 0 || n == 1)
            return false;
        for (int i = 0; i < n; i++)
        {
            if (auto ist = set.insert(nums[i]); ist.second != true)
                return true;
            if (set.size() > k)
                set.erase(nums[i - k]);
        }
        return false;
    }
};
