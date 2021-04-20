#include <algorithm>
#include <array>
using std::array;
using std::max;

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
    //Method 1:
    // public:
    //     int rob(TreeNode* root) {
    //         if(root==nullptr) return 0;
    //         // 查找备忘录，寻找所需的root节点；
    //         // if(auto fd=demo.find(root);fd!=demo.end()) return max((fd->second)[0],(fd->second)[1]);
    //         if(demo.find(root)!=demo.end())
    //         {
    //             array<int,2> & fd=demo[root];
    //             return max(fd[0],fd[1]);
    //         }
    //         //选取当前节点偷窃a[0],不选取当前节点偷a[1]
    //         array<int,2> a;
    //         a[0]=root->val+
    //                 ((root->left==nullptr)?0:(rob(root->left->left)+rob(root->left->right)))+
    //                 ((root->right==nullptr)?0:(rob(root->right->left)+rob(root->right->right)));
    //         a[1]= rob(root->left)+rob(root->right);
    //         demo.insert(make_pair(root,a));
    //         return max(a[0],a[1]);
    //     }

    // private:
    //     unordered_map<TreeNode*,array<int,2>> demo;
public:
    //Method 2
    typedef array<int, 2> arr;
    int rob(TreeNode *root)
    {
        array<int, 2> a = dp(root);
        return max(a[0], a[1]);
    }

    arr dp(TreeNode *root)
    { //做好当前工作，递归调用
        if (root == nullptr)
            return arr{0, 0};
        //lvalue[0] 不抢当前节点而获取的最大收获，lvalue[1] 抢当前节点而获取的最大收获
        arr lvalue = dp(root->left);
        arr rvalue = dp(root->right);
        int in_rob = root->val + lvalue[0] + rvalue[0];
        int not_rob = max(lvalue[0], lvalue[1]) + max(rvalue[0], rvalue[1]);
        return arr{not_rob, in_rob};
    }
};