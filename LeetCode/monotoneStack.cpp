#include <vector>
#include <stack>
using std::stack;
using std::vector;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        int n = T.size();
        if (n == 0)
            return vector<int>();
        if (n == 1)
            return vector<int>(1, 0);
        stack<int> st;
        vector<int> vec(n, 0);
        for (int i = 0; i < n; i++)
        { //stack记录索引
            while (!st.empty() && (T[st.top()] < T[i]))
            {
                int &temp = st.top();
                vec[temp] = i - temp;
                st.pop();
            }
            st.push(i);
        }
        return vec;
    }
};
