//存在重复的元素
#include <vector>
#include <unordered_set>
using std::unordered_set;
using std::vector;
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> set;
        for (int i : nums)
        {
            if (set.find(i) != set.end())
                return true;
            set.insert(i);
        }
        return false;
    }
};
