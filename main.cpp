#include <iostream>
#include <map>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

class Solution
{
public:
    int maximumRemovals(string s, string p, vector<int> &removable)
    {
        int n = s.size();
        if (p.size() == 0)
            return n;

        vector<int> state(n, 1);
        int head = 0, tail = removable.size() - 1, half = (head + tail) / 2;

        for (; head != tail; half = (head + tail) / 2)
        {
            for (int i = head; i <= half; i++)
                state[removable[i]] = 0;

            cout << s << "\t" << p << "\t";
            for (int i = 0; i < n; i++)
                cout << state[i] << "  ";
            cout << endl;

            if (!checkIsSequence(s, p, state))
            {
                for (int i = head; i <= half; i++)
                    state[removable[i]] = 1;
                tail = half; //tail后退
            }
            else
            {
                head = half + 1; //head前进
            }
        }

        //head==tail时，删除head是否仍然是子序列？
        state[removable[head]] = 0;
        if (!checkIsSequence(s, p, state))
        {
            return head;
        }
        return head + 1;
    }

    bool checkIsSequence(string s, string p, vector<int> &state)
    {
        int n = state.size();
        int i = 0;
        for (char ch : p)
        {
            while (i < n && ((state[i] == 1 && s[i] != ch) || state[i] == 0))
                i++;
            //说明p未匹配完
            if (i >= n)
                return false;
            i++;
        }
        return true;
    }
};

int main()
{

    vector<int> num = {3, 1, 0};
    string s = "abcabc";
    string p = "ab";
    Solution solu;
    cout << solu.maximumRemovals(s, p, num) << endl;
}