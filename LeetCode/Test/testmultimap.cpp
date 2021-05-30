#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <queue>
#include <cstdio>
#include <vector>

using std::cout;
using std::endl;
using std::queue;
using std::snprintf;
using std::string;
using std::unordered_multimap;
using std::vector;

int main()
{
    unordered_multimap<std::string, std::string> mp = {{"a", "aaa"}, {"b", "bbbb"}};
    mp.insert({"a", "ababab"});
    mp.insert(std::make_pair("a", "acac"));
    mp.insert({"c", "cccc"});
    mp.insert({"b", "bbbbbbbb"});
    //since bucket maybe before or behind "a" bucket,then maybe not output "c" tag;
    for (auto fd = mp.find("a"); fd != mp.end(); fd++)
    {
        cout << fd->first << "\t" << fd->second << endl;
    }
    cout << "............." << endl;
    for (auto fd = mp.begin(); fd != mp.end(); fd++)
    {
        cout << fd->first << "\t" << fd->second << endl;
    }

    cout << ".............." << endl;
    auto fd = mp.equal_range("a"); //精确查找键对应的所有值
    for (auto begin = fd.first; begin != fd.second; begin++)
    {
        cout << begin->first << "\t" << begin->second << endl;
    }

    //尽管使用这种数据结构，体现不了索引的加减等等效果比较大小（jumpgame6.cpp)
    unordered_multimap<int, std::pair<int, int>> map = {{100, {1, 0}}, {200, {2, 1}}};
    map.insert({100, {1, 2}});
    map.insert({100, {1, 1}});
    auto fds = map.equal_range(100);
    for (auto bg = fds.first; bg != fds.second; bg++)
    {
        cout << bg->first << "\t\t" << bg->second.first << "\t" << bg->second.second << endl;
    }

    queue<int> dp;
    for (int i = 0; i < 5; i++)
    {
        dp.push(i);
    }
    cout << "dq........" << endl;
    cout << dp.size() << endl;
    dp.pop();
    dp.pop();
    cout << dp.size() << endl;
    dp.push(100);
    cout << dp.size() << endl;
    int n = dp.size();
    for (int i = 0; i < n; i++)
    {
        cout << dp.front() << "\t";
        dp.pop();
    }
    // cout << "dp front......." << dp.front() << endl;
    // dp.pop();
    // cout << dp.front() << endl;
    // cout << "first for" << endl;
    // while (!dp.empty())
    // {
    //     cout << dp.front() << "\t";
    //     dp.pop();
    // }

    queue<string> str;
    char buf[20];
    for (int i = 0; i < 5; i++)
    {
        snprintf(buf, 20, "value %d", i);
        str.push(string(buf));
    }
    cout << "string........" << endl
         << str.size() << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << str.front() << endl;
        str.pop();
    }
    cout << "############" << endl;
    snprintf(buf, 20, "later value %d", 10);
    str.push(buf);
    snprintf(buf, 20, "later value %d", 20);
    str.push(buf);
    while (!str.empty())
    {
        cout << str.front() << endl;
        str.pop();
    }

    if (int i = 10; i < 9)
    {
        cout << "less than 9" << endl;
    }
    else if (i == 10)
    {
        cout << "equal to 10" << endl;
    }

    vector<int> arr = {7, 6, 8, 6, 8, 6, 8, 6, 8, 7};
    // vector<int> tmp;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     while (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2])
    //     {
    //         i++;
    //     }
    //     tmp.emplace_back(arr[i]);
    // }
    // for (auto i : tmp)
    //     cout << i << "\t";
    // cout << endl;
    // arr = std::move(tmp);
    // for (auto i : arr)
    //     cout << i << "\t";
    // cout << endl;
    // cout << arr.size() << endl;

    vector<int> tmp;
    for (int i = 0; i < arr.size(); i++)
    {
        while (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2])
        {
            i++;
        }
        tmp.emplace_back(arr[i]);
    }
    // arr=move(tmp);
    arr = tmp;
    for (int i : arr)
        cout << i << endl;
}
