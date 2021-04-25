//给定二叉树，找出路径和等于给定数值的路径总数，路径只能从父节点到叶子节点，而且不一定从根节点开始，也不一定从叶子节点结束

//双递归方式。
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//分成两种情况，1.当前节点作为初始节点，2.当前节点作为上一个节点的后续节点
class Solution
{
public:
    //压缩重复代码
    // int pathSum(TreeNode* root, int targetSum) {
    //     if(root==nullptr) return 0;
    //     target = targetSum;
    //     targetSum -= root->val;
    //     if(targetSum==0) ++len;
    //     path(root->left,targetSum);
    //     path(root->right,targetSum);
    //     // path(root,targetSum);
    //     return len;
    // }

    // void path(TreeNode* root, int targetSum){
    //     //当前函数开启以当前节点开始的序列
    //     if(root==nullptr) return;
    //     //延续上一层穿过的节点
    //     pathAllPart(root,targetSum);

    //     //以当前节点作为起始节点
    //     int temp =target - root->val;
    //     if(temp==0) ++len;
    //     path(root->left,temp);
    //     path(root->right,temp);
    //     return;
    // }
    int pathSum(TreeNode *root, int targetSum)
    {
        //可以认为是pathSum遍历节点，pathAllPart处理节点
        if (root == nullptr)
            return 0;
        pathAllPart(root, targetSum);    //当前节点一直向下搜寻
        pathSum(root->left, targetSum);  //当前左节点作为起始节点
        pathSum(root->right, targetSum); //当前右节点作为起始节点
        return len;
    }

    void pathAllPart(TreeNode *root, int targetSum)
    {
        //从当前节点一直向下取到叶子节点
        if (root == nullptr)
            return;
        targetSum -= root->val;
        if (targetSum == 0)
            ++len;
        pathAllPart(root->left, targetSum);
        pathAllPart(root->right, targetSum);
        return;
    }

private:
    int len = 0;
};
