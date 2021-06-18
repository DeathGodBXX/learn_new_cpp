#include <iostream>
#include <map>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;
class myMap
{
public:
    myMap() = default;
    ~myMap();
    // void setMap(); 伪代码必须定义之后才能使用。

private:
    map<int, int> mp;
};

class Solution
{
public:
    int maximumRemovals(string s, string p, vector<int> &removable)
    {
        int n = removable.size();
        cout << "p" << p << endl;
        for (int i = 0; i < n; i++)
        {
            s[removable[i]] = ' ';
            if (!contains(s, p))
                return i;
            cout << "s:" << s << "\t"
                 << "num:" << removable[i] << endl;
        }
        return n;
    }

    bool contains(string s, string p)
    {
        if (p.size() == 0)
            return true;
        auto itr = s.begin();

        for (char ch : p)
        {
            while (*itr != ch && itr != s.end())
                ++itr; //*itr=ch跳出循环,或者itr=s.end()
            if (itr == s.end())
                return false; //走到结尾都没有匹配到ch，说明匹配不到，返回false
        }

        return true;
    }
};

int main()
{
    // myMap *mp = new myMap;
    // // mp->setMap();
    // cout << "False code:Finished!!" << endl;

    string str = "abcacb";
    // str.erase(0, 2);
    str.erase(3, 1);
    cout << str << endl;

    char ss = 'a';
    cout << (ss == 'b') << endl;

    vector<int> num = {5, 3, 0, 6, 4, 9, 10, 7, 2, 8};
    string s = "qobftgcueho";
    string p = "obue";
    Solution solu;
    cout << solu.maximumRemovals(s, p, num) << endl;

    string s1 = "a b ";
    cout << s1.length() << endl;
}