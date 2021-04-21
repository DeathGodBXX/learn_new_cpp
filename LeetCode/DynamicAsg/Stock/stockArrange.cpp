//利用单调栈计算当前股票价格的时间跨度(小于等于当前价格的最大连续日数(从当前位置往回数))

#include <vector>
#include <utility>
#include <stack>
using std::pair;
using std::stack;
using std::vector;

class StockSpanner
{
public:
    StockSpanner(){

    };

    // int next(int price) {
    //     int times=1;
    //     while(!st.empty()){
    //         pair<int,int> top=st.top();
    //         if(price<top.first) {st.push(make_pair(price,times));break;}
    //         times += top.second;
    //         st.pop();
    //     }
    //     if(st.empty()) st.push(make_pair(price,times));
    //     return times;
    // }
    int next(int price)
    {
        int times = 1;
        while (!st.empty() && price >= st.top().first) //如果栈为空或者当前数值小于栈顶数值，则将当前价格和跨度直接放入stack中
        {
            times += st.top().second;
            st.pop();
        }
        st.push({price, times});
        return times;
    }

private:
    stack<pair<int, int>> st; //存储价格和当前价格对应的跨度
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */