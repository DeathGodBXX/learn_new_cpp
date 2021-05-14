#include "../header.h"

bool canReach(vector<int> &arr, int start)
{
    int n = arr.size();
    stack<int> st;
    st.push(start);
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (arr[top] == 0)
        {
            arr[top] = -1;
            continue;
        }
        if (top + arr[top] < n)
            st.push(top + arr[top]);
        if (top - arr[top] >= 0)
            st.push(top - arr[top]);
    }
    vector<int>::iterator it = find(arr.begin(), arr.end(), 0);
    if (it != arr.end())
        return false;
    return true;
}

int main()
{
    vector<int> arr{4, 2, 3, 0, 3, 1, 2};
    cout << canReach(arr, 5) << endl;
}

// 编译命令clang++ -std=c++17  -g  -Wall -static-libgcc -fcolor-diagnostics --target=x86_64-w64-mingw test.cpp