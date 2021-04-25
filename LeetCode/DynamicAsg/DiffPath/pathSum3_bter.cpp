//differentPath3的另一种解法
//时间复杂度和空间复杂度都是o(N),以空间换时间
//用的方法是前缀和，遍历到某个节点时，在hash中查找前缀和为prefix_sum-sum的节点的个数，
//结果等于这个个数加上左右子树中满足条件的节点个数
#include <unordered_map>
using std::unordered_map;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        mp[0] = 1;
        return calPrefix(root, targetSum, 0);
    }

    int calPrefix(TreeNode *root, int targetSum, int prefixSum)
    {
        //前缀和都是从根节点开始，需要找到targetSum的路径，则前缀和为prefixSum+root->val - targetSum 节点个数就是当前可行的额外总数;
        if (root == nullptr)
            return 0;
        int res = 0;
        prefixSum += root->val;           //当前节点的前缀和prefixSum
        res += mp[prefixSum - targetSum]; //回退到前面节点的前缀和=prefixSum-targetSum,两者相减就是targetSum
        mp[prefixSum]++;                  //存储当前节点之前的的所有的前缀和，也就说为递归左右子树做准备
        res += calPrefix(root->left, targetSum, prefixSum) + calPrefix(root->right, targetSum, prefixSum);
        //计算左右子树等于target的路径(注意于root不同，左右子树以左右子树作为结束节点)
        mp[prefixSum]--; //回退到当前root节点，函数栈再递归向上回退
        return res;
    }

private:
    unordered_map<int, int> mp;
};