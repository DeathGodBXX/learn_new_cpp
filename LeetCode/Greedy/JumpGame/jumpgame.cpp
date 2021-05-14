#include <../header.h>

//method1:too slow algorithm
// class Solution
// {
// public:
//     bool canJump(vector<int> &nums)
//     {
//         int n = nums.size();
//         if (n == 0)
//             return false;
//         if (n == 1)
//             return true;

//         stack<int> st;
//         vector<int> visit(n, 0);

//         st.push(0);
//         while (!st.empty())
//         {
//             //内部做遍历操作
//             int pos = st.top();
//             st.pop();

//             //提前找到最后一个下标，跳出函数；同时作为函数越界与否的边界检查
//             if (nums[pos] + pos >= n - 1)
//                 return true;

//             //visit存储的是stack的访问对象
//             visit[pos] = 1;

//             //对visit数组的遍历导致的耗时，每次都需要遍历visit数组查看是否访问过
//             for (int i = 1; i <= nums[pos] && visit[pos + i] != 1; i++)
//             {
//                 st.push(pos + i);
//             }
//         }

//         return false;
//     }
// };

//method2: maintain rightmost to represent whether can arrive.
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        //dynamic arrangement,meanwhile using dynamic thought to consider this problem
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; i++)
        {
            if (i <= rightmost)
            {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1)
                    return true;
            }
            else
            {
                return false;
            }
        }
        return false;
    }
};
