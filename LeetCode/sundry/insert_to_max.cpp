/*
leetcode 1881.插入后最大值
给你一个非常大的整数 n 和一个整数数字 x ，大整数 n 用一个字符串表示。n 中每一位数字和数字 x 都处于闭区间 [1, 9] 中，且 n 可能表示一个 负数 。

你打算通过在 n 的十进制表示的任意位置插入 x 来 最大化 n 的 数值 ​​​​​​。但 不能 在负号的左边插入 x 。

例如，如果 n = 73 且 x = 6 ，那么最佳方案是将 6 插入 7 和 3 之间，使 n = 763 。
如果 n = -55 且 x = 2 ，那么最佳方案是将 2 插在第一个 5 之前，使 n = -255 。
返回插入操作后，用字符串表示的 n 的最大值

*/
#include <string>
using std::string;
class Solution
{
public:
    string maxValue(string n, int x)
    {
        //效率不高，这大概是由于insert效率太差
        // char charx=static_cast<int>(x); 会丢失精度，用c形式的itoa做转换
        // char charx[4];
        // itoa(x,charx,10);
        //string类型上比较，然后直接插入
        char charx = x + '0'; //简单的类型转换，把整数转换为char
        string::iterator in = n.begin();
        if (*in == '-')
        {
            in++;
            while (in != n.end() && *in <= charx)
                in++;
        }
        else
        {
            //找到第一个比当前值小的位置
            while (in != n.end() && *in >= charx)
                in++;
        }
        n.insert(in, charx);
        return n;
    }

    //效率和内存极其低下
    // string maxValue(string n, int x) {
    //     int size=n.size();
    //     vector<char> vec(size+1,0);
    //     char charx=x+'0';
    //     for(int i=0;i<size;i++) vec[i]=n[i];
    //     int in=0;
    //     if(vec[in]=='-'){
    //         in++;
    //         while(in<size&&vec[in]<=charx) ++in;
    //     }else{
    //         while(in<size&&vec[in]>=charx) ++in;
    //     }
    //     for(int i=size-1;i>=in;i--) vec[i+1]=vec[i];
    //     vec[in]=charx;
    //     n.assign(vec.begin(),vec.end());
    //     return n;
    // }
};