#include <iostream>
#include <vector>

using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//寻找等于指定和的所有路径。
class Solution
{
public:
    //通过左右指针控制节点的跳转
    //这里有递归的步骤，不需要返回值，已经在ret缓存起来了
    void searchPath(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return;
        cache.emplace_back(root->val);
        sum -= root->val;
        if (root->left == nullptr && root->right == nullptr && sum == 0)
            //无论如何都要弹出上一步处理的val,这里如果直接返回，会把满足条件的值未删除，就跳转到父节点。
            ret.emplace_back(cache);
        searchPath(root->left, sum);
        searchPath(root->right, sum);
        cache.pop_back();
        return;
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        searchPath(root, targetSum);
        return ret;
    }

private:
    vector<vector<int>> ret; //记录最终结果
    vector<int> cache;       //缓存当前查询到的路径值
};