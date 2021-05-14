#include <../header.h>

// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int n=nums.size();
//         if(n==0||n==1) return 0;
//         int left=0,right=nums[0],step=1;

//         //如果当前step=k，最远的位置是right,则需要在step=k-1,最远位置是left；在(left,right]之间寻找最远跳跃的位置,(注意如果在第k-1位置以及之前寻找,最远跳跃位置就是第k次跳跃最远位置,否则会产生矛盾))
//         while(right<n-1){
//             int rightmost=right;
//             for(;left<=right;left++){
//                 rightmost=max(rightmost,nums[left]+left);
//             }
//             //增加step次数未能往后走，也就是到不了末尾，失败
//             if(rightmost==right) return -1;
//             left=right;
//             right=rightmost;
//             step++;
//         }
//         return step;
//     }
// };
//简化代码版本
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0 || n == 1)
            return 0;
        int end, now, step;
        end = now = step = 0;
        int max_pos = 0;
        while (end < n - 1)
        { //这里的now就是上一个的left
            max_pos = max(max_pos, nums[now] + now);
            if (now == end)
            {
                step++;
                end = max_pos;
            }
            now++;

            //可用于检查是否可以跳到末尾，但是效率极慢。
            if (now > end)
                return -1; //如果有某个step的now++到end后面，说明end不再移动,end先更新后比较
        }
        return step;
    }
};