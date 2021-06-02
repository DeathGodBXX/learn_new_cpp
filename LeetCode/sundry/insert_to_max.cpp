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