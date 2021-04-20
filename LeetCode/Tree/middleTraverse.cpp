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

//中序遍历
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        //root用于指向左子树，正常出栈入栈
        vector<int> ret;
        if (root == nullptr)
            return ret;
        stack<TreeNode *> cache;
        while (root != nullptr || !cache.empty())
        {
            while (root != nullptr)
            {
                cache.push(root);
                root = root->left;
            }
            //这是左子树必为空，弹出根节点，再转到右子树
            root = cache.top();
            ret.emplace_back(root->val);
            cache.pop();
            root = root->right;
            //本质上也是将非空root->right入栈,等同于上面的while循环
            // if(root->right!=nullptr){
            //     cache.push(root->right);
            //     root=root->right->left;
            // }else{
            //     root=nullptr;
            // }
        }
        return ret;
    }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     middleTraversal(root);
    //     return ret;
    // }
    // void middleTraversal(TreeNode* root){
    //     if(root==nullptr)return;
    //     if(root->left!=nullptr) middleTraversal(root->left);
    //     ret.emplace_back(root->val);
    //     if(root->right!=nullptr) middleTraversal(root->right);
    // }
};