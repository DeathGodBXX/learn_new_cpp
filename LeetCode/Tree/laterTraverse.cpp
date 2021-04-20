#include <vector>
#include <stack>
using std::stack;
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

//迭代法后序遍历二叉树。
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        traverse(root);
        return ret;
    }

    void traverse(TreeNode *root)
    {
        if (root == nullptr)
            return;
        // cache.push(root);
        TreeNode *prev = nullptr;
        //prev记录从何处返回的,root记录是否遍历过所有右节点或在空右节点
        while (root != nullptr || !cache.empty())
        {
            //遍历到最左节点
            while (root != nullptr)
            {
                cache.push(root);
                root = root->left;
            }
            //处理从左节点跳出情况
            root = cache.top();
            cache.pop();
            if (root->right == nullptr || root->right == prev)
            {
                //prev唯一修改跳转点的变量
                //如果当前节点右节点为空，ret记录val；prev记录从何处跳转过来的；root=nullptr表示不用重复while步骤，再次遍历到最左节点(处理全是左节点的情况)
                //如果当前节点的右节点等于之前跳转的prev；prev记录当前数值跳转点；从右子树归来的节点不需要重复while步骤。(处理从右节点归来的情形。)
                ret.emplace_back(root->val);
                prev = root;
                root = nullptr;
            }
            else
            {
                //如果当前节点不是从右节点跳转过来的，而且当前节点右节点非空，再次将当前节点入栈，再处理右节点。
                cache.push(root);
                root = root->right;
            }
        }
    }

    //递归方法
    // vector<int> traverse(TreeNode* root){
    //     traversePart(root);
    //     return ret;
    // }
    // void traversePart(TreeNode* root){
    //     if(root==nullptr) return;
    //     traversePart(root->left);
    //     traversePart(root->right);
    //     ret.emplace_back(root->val);
    // }
private:
    vector<int> ret;
    stack<TreeNode *> cache;
};