#include <algorithm>
#include <unordered_map>
using std::max;
using std::min;
using std::unordered_map;
class Solution
{
public:
    int superEggDrop(int k, int n)
    {
        return dp(k, n);
    }

    int dp(int k, int n)
    {
        if (mp.find(n * 100 + k) != mp.end())
            return mp[n * 100 + k];
        if (k == 1)
        {
            mp[n * 100 + k] = n;
            return n;
        }
        if (n == 0)
        {
            mp[n * 100 + k] = 0;
            return 0;
        }
        int low = 1, high = n;
        while (low + 1 < high)
        {
            int mid = (low + high) / 2;
            int t1 = dp(k - 1, mid - 1); //碎了
            int t2 = dp(k, n - mid);     //没碎
            if (t1 < t2)
                low = mid + 1;
            else if (t1 > t2)
                high = mid - 1;
            else
                low = high = mid;
        }
        mp[n * 100 + k] = 1 + min(max(dp(k - 1, low - 1), dp(k, n - low)),
                                  max(dp(k - 1, high - 1), dp(k, n - high)));
        return mp[n * 100 + k];
    }

private:
    unordered_map<int, int> mp;
    //使用map代替二维数组，这是由于1<=k<=100，将n*100避免冲突。
};