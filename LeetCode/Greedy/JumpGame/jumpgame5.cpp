#include "../header.h"
class Solution
{
public:
    // int maxResult(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     if(n==0) return 0;
    //     if(n==1) return nums[0];
    //     if(k>=n){
    //         int res=nums[0];
    //         for(int i=1;i<n-1;i++){
    //             if(nums[i]>0) res += nums[i];
    //         }
    //         return res+nums[n-1];
    //     }
    //     //以数组当前位置结尾可获取的最大值，故而跳跃阶数是k,最多以k个元素结尾的数组值作为ktag;
    //     vector<int> ktag(k,0);
    //     //初始化k阶数组
    //     ktag[0]=nums[0];
    //     int temp=INT_MIN;
    //     if(k>=2) {ktag[1]=nums[0]+nums[1];temp=max(ktag[1],ktag[0]);}
    //     for(int i=2;i<k;i++){
    //         ktag[i]=temp+nums[i];
    //         temp=max(temp,ktag[i]);
    //     }
    //     for(int i=k;i<n;i++){
    //         //耗时操作每次都要遍历k阶数组，时间复杂度是O(nk)会导致超时。
    //         ktag[i%k]=*max_element(ktag.begin(),ktag.end())+nums[i];
    //     }
    //     return ktag[(n-1)%k];
    // }
    int maxResult(vector<int> &nums, int k)
    {
        //利用deque双向vector，将数值大的且下标小的放在头部，数值小的且下标大的放在尾部。
        int n = nums.size();
        deque<pair<int, int>> dq;
        dq.emplace_back(std::make_pair(nums[0], 0));
        int ans = nums[0];
        for (int i = 1; i < n; i++)
        {
            //不满足范围的下标删除
            while (i - dq.front().second > k)
            {
                dq.pop_front();
            }
            ans = dq.front().first + nums[i];
            //利用队列存储递减的数列，就省得每次比较大小了，队首为最大的且下标是最小的；
            //这是因为下标小的，数值也小的，必然会被下标大的，数值更大的替代。
            while (!dq.empty() && dq.back().first <= ans)
            {
                dq.pop_back();
            }
            dq.emplace_back(std::make_pair(ans, i));
        }
        return ans;
    }
};
