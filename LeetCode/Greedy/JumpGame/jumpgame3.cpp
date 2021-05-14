//从起始点start，跳到某一个0处，为真，否则为假。
//没有0为假的，有0跳不到也是假的，否则为真
#include <../header.h>

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        vector<int>::iterator it = find(arr.begin(), arr.end(), 0);
        if (it == arr.end())
            return false;
        int n = arr.size();
        vector<bool> flag(n, false);
        stack<int> st;
        st.push(start);
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            if (arr[top] == 0)
            {
                return true;
            }
            if (top + arr[top] < arr.size() && !flag[top + arr[top]])
            {
                st.push(top + arr[top]);
                flag[top + arr[top]] = true;
            }
            if (top - arr[top] >= 0 && !flag[top - arr[top]])
            {
                st.push(top - arr[top]);
                flag[top - arr[top]] = true;
            }
        }
        return false;
    }
};