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

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        haspathSum(root, targetSum);
        return ans;
    }

    void haspathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return;
        //失败的情形，必然不会有root->left==nullptr,root->right==nullptr,targetSum==0同时成立
        targetSum -= root->val;
        vec.emplace_back(root->val);
        //placement new，临时对象直接move，非临时对象也是copy构造函数，而push_back直接拷贝构造
        //总而言之，第一个emplace_back不会有额外的析构函数，第二个emplace_back的效果和push_back一致
        if (root->left == nullptr && root->right == nullptr && targetSum == 0)
        { //成功的情形
            ans.emplace_back(vec);
        }
        haspathSum(root->left, targetSum);
        haspathSum(root->right, targetSum);
        vec.pop_back();
        return;
    }

private:
    vector<vector<int>> ans;
    vector<int> vec;
};