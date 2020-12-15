#include<iostream>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};
/*
给定一个二叉树，它的每个结点都存放着一个整数值。
找出路径和等于给定数值的路径总数。
路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
*/

class Solution {
    int res = 0;
    void dfs(TreeNode* root, int sum) {
        if (!root)
            return;
        sum -= root->val;
        if (sum == 0)
            ++res;
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return res;
        //if(!root->left&&!root->right)
        //路径不需要从根节点开始，也不需要在叶子节点结束
        dfs(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return res;
    }
};

//class Solution {
//public:
//    bool hasPathSum(TreeNode* root, int sum) {
//        if (!root)
//            return false;
//        if (!root->left && !root->right)
//            return sum - root->val == 0;
//        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
//    }
//};
