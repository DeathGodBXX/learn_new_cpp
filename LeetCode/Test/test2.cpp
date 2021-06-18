#include <string>
#include <iostream>
#include <vector>
// #include <cstdlib>
// #include <type_traits>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string str = "-123442";
    cout << str << endl;
    int n = std::stoi(str);
    std::cout << n << std::endl;

    std::string str1 = "-2344214214321412414214124141414";
    vector<int> vec;
    cout << *str1.begin() << endl;
    if (auto it = str1.begin(); *it != '-')
        cout << "not -" << endl;
    for (auto it = str1.begin() + 1; it != str1.end(); it++)
    {
        vec.emplace_back(*it - '0');
    }
    for (int i : vec)
        cout << i << "\t";
    cout << endl;

    // cout << "......." << endl;
    // string strcopy;
    // std::cout << strcopy.assign(vec.begin(), vec.end()) << endl;
    // cout << strcopy << endl;

    string str2 = "-134234124141";
    vector<int> vec2;
    vec2.assign(str2.begin(), str2.end());
    for (auto i : vec2)
        cout << i << endl;

    cout << "......" << endl;
    cout << '0' + 3 << "\t" << ('3' == '0' + 3) << '0' << endl;
    cout << '-' << endl;
    cout << "#####" << endl;

    //0-9 to char.....
    string s = "-123";
    cout << s.front() << "\t" << (s.back() == '3') << "\t" << (s.back() > '4') << "\t" << (s.back() < '2') << endl;
    cout << *(++s.begin()) << endl;
    int a = 1;
    char c = static_cast<int>(a);
    if (std::is_same<decltype(c), char>::value)
        cout << "right" << endl;

    // auto begin=s.begin();
    string::iterator begin;
    begin = s.begin();
    cout << *(++begin) << endl;
    cout << *(++begin) << endl;
    cout << *s.end() << endl;
    cout << "######" << endl;

    string s1 = "1245";
    int x = 3;
    char charx[4];
    itoa(x, charx, 10);
    if (*charx == '3')
        cout << "right" << endl;
    cout << charx << endl;
    auto in = s1.begin();
    // cout << *in << "\t" << *(++in) << endl;
    while (in != s1.end() && *in < *charx)
        in++;
    s1.insert(in, *charx);
    cout << s1 << endl;

    cout << "------------" << endl;
    char charxx = 3 + '0';
    cout << (charxx == '3') << endl;
    cout << "------------" << endl;

    //string to integer....
    cout << "**********" << endl;
    string strxx = "-12347893";
    int xx = std::stoul(strxx);
    cout << xx << endl;
    cout << strxx.size() << endl;
    vector<int> vec3(strxx.size(), 0);
    int i = 0;
    for (auto begin = strxx.begin(); begin != strxx.end(); begin++)
    {
        vec3[i] = *begin - '0';
        i++;
    }
    for (int &i : vec3)
        cout << i << endl;
    cout << "---------" << endl;
    vector<int> vec4(strxx.size(), 0);
    // int j = 0;
    // for (char &i : strxx)
    // {
    //     vec4[j] = i - '0';
    //     j++;
    // }
    for (int j = 0; j < strxx.size(); j++)
        vec4[j] = strxx[j] - '0';
    for (int &i : vec4)
        cout << i << endl;
}