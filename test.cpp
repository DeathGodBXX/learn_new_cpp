#include <iostream>
#include <tuple>
#include <vector>
#include <set>

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
    set<int> set;
    tie(ignore, result) = set.insert(1); //解包，std::pair<iterator,bool>
    cout << result << endl;

    vector<int> vec(6);
    cout << vec.size() << endl;
    for (int &i : vec)
        cout << i << "\t";
    cout << endl;
}