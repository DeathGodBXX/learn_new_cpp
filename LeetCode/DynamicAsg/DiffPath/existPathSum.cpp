//二叉树是否存在从根节点到叶子节点的targetSum数值的路径。
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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr && targetSum == 0)
            return true;
        //只有当上述同时成立时，才返回true;上述是唯一的终止true的条件。
        //如果targetSum!=0,root->left==nullptr,返回false,接下来对于root->right执行和root相同的操作，同理于root->right==nullptr;如果都不是nullptr,那么执行root->left and root->right和root一样
        //如果targetSum==0,root->left==nullptr，返回false，接下来对于root->right执行和root相同的操作，同理于root->left==nullptr;如果都不是nullptr,那么执行root->left and root->right和root一样
        //也就说在执行当前if之后，再递归调用root->left,root->right,肯定不会使得nullptr,nullptr,0同时存在，必然返回false;
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};