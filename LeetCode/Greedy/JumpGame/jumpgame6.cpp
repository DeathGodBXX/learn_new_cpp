/*jumpgame IV
给你一个整数数组 arr ，你一开始在数组的第一个元素处（下标为 0）。

每一步，你可以从下标 i 跳到下标：

i + 1 满足：i + 1 < arr.length
i - 1 满足：i - 1 >= 0
j 满足：arr[i] == arr[j] 且 i != j
请你返回到达数组最后一个元素的下标处所需的 最少操作次数

*/
#include <unordered_map>
#include <vector>
#include <queue>

using std::queue;
using std::unordered_multimap;
using std::vector;

// class Solution
// {
// public:
//     int minJumps(vector<int> &arr)
//     {
//         if (arr.size() == 1)
//             return 0;
//         //数组去重
//         vector<int> tmp;
//         int size = arr.size();
//         for (int i = 0; i < arr.size(); i++)
//         {
//             while (i + 1 < size && i + 2 < size && arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2])
//             {
//                 i++;
//             }
//             tmp.emplace_back(arr[i]);
//         }
//         arr = move(tmp);
//         // arr=tmp;
//         size = arr.size();
//         //根据值快速查找对应的索引
//         unordered_multimap<int, int> map;
//         //deque从中获取要操作的索引
//         queue<int> dp;
//         //定义一个新vector，存储需要的steps
//         vector<int> step(size, INT_MAX);
//         //初始化mp
//         for (int i = 0; i < size; i++)
//         {
//             map.insert({arr[i], i});
//         }
//         dp.push(0); //index扔到dp中
//         step[0] = 0;

//         int dis = 0;
//         while (!dp.empty())
//         {
//             //每一次穷尽当前dis层下的index
//             dis++;
//             int n = dp.size();
//             for (int i = 0; i < n; i++)
//             {

//                 int front = dp.front();
//                 dp.pop();
//                 if (int before = front - 1; before > 0 && step[before] > dis)
//                 { //初始化的INT_MAX或者之前修改的小值，不可能会增大
//                     step[before] = dis;
//                     dp.push(before);
//                 }
//                 //不间断的能够找到front++在dp中，不需要做后续操作，直接往后遍历即可
//                 if (int after = front + 1; after < size && step[after] > dis)
//                 {
//                     step[after] = dis;
//                     dp.push(after);
//                 }                                       //可能提前结束循环
//                 auto fds = map.equal_range(arr[front]); //return std::pair<iterator,iterator> start,end
//                 for (auto it = fds.first; it != fds.second; it++)
//                 {
//                     if (it->second != front && step[it->second] > dis)
//                     {
//                         step[it->second] = dis;
//                         dp.push(it->second);
//                     }
//                 }
//             }
//         }
//         return step[size - 1];
//     }
// };
class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        if (arr.size() == 1)
            return 0;

        //arr去重
        remove_dup(arr);

        int size = arr.size();
        //根据值快速查找对应的索引
        unordered_multimap<int, int> map;
        //deque从中获取可被操作的索引
        queue<int> dp;
        //定义一个新vector，存储需要的steps
        vector<int> step(size, INT_MAX);
        //初始化mp
        for (int i = 0; i < size; i++)
        {
            map.insert({arr[i], i});
        }
        dp.push(0); //index扔到dp中
        step[0] = 0;

        //核心点在于每次必须到达的最少操作数，都是前面最小操作数+1，对于左侧右侧和同值比较大小
        int dis = 0;
        while (!dp.empty())
        {
            //每一次穷尽当前dis层下的index
            dis++;
            int n = dp.size();
            for (int i = 0; i < n; i++)
            {
                //控制走完当前dis步的索引
                int front = dp.front();
                dp.pop();
                if (int before = front - 1; before > 0)
                    change_step_and_dp(dis, before, dp, step);
                if (int after = front + 1; after < size)
                    change_step_and_dp(dis, after, dp, step);
                else if (after = size - 1)
                    return dis - 1;                     //已经定位到末尾节点，提前返回，节省了将近1/4的时间
                auto fds = map.equal_range(arr[front]); //return std::pair<iterator,iterator> start,end
                for (auto it = fds.first; it != fds.second; it++)
                {
                    if (it->second != front)
                        change_step_and_dp(dis, it->second, dp, step);
                }
            }
        }
        return step[size - 1];
    }

    //如果之前记录的值比当前值大的话，修改到达idx的步距和记录dp当前步距的idx
    //这种情况就是设定的INT_MAX,因为后续dis是单调递增的。
    void change_step_and_dp(int dis, int idx, queue<int> &dp, vector<int> &step)
    {
        if (step[idx] > dis)
        {
            step[idx] = dis;
            dp.push(idx);
        }
    }

    //arr去重
    void remove_dup(vector<int> &arr)
    {
        bool tag = false;
        int size = arr.size();
        vector<int> tmp;
        for (int i = 0; i < size; i++)
        {
            while (i + 1 < size && i + 2 < size && arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2])
            {
                i++;
                tag = true;
            }
            tmp.emplace_back(arr[i]);
        }
        if (tag)
            arr = move(tmp); // arr=tmp;
    }
};