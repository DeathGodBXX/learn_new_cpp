#include <iostream>
#include <tuple>
#include <vector>
#include <set>
#include <algorithm>
using std::cout;
using std::endl;
using std::ignore;
using std::set;
using std::tie;
using std::tuple;
using std::vector;
int main()
{
    int a;
    double b;
    const char *c;
    tie(a, b, c) = std::make_tuple(1, 2.0, "express"); //解包元组
    cout << a << "\t" << b << "\t" << c << endl;

    bool result;
    set<int> set2;
    tie(ignore, result) = set2.insert(1); //解包，std::pair<iterator,bool>
    cout << result << endl;

    vector<int> vec(6);
    cout << vec.size() << endl;
    for (int &i : vec)
        cout << i << "\t";
    cout << endl;

    set<int> set1{1, 2, 3, 5};
    cout << "---------" << endl
         << *set1.end() << endl //set.end()最后一个元素是元素个数 4
         << *set1.rbegin() << endl;
    for (int i : set1)
        cout << i << endl;

    abs(1 - 2);
    std::min<long>(1, 1);
}