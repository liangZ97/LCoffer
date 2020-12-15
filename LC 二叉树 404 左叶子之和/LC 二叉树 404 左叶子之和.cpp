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
计算给定二叉树的所有左叶子之和。
示例：
    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
*/

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;
        //int leftSum = sumOfLeftLeaves(root->left);
        //int rightSum = sumOfLeftLeaves(root->right);

        int curSum = 0;
        if (root->left && !root->left->left && !root->left->right)
            curSum = root->left->val;
        return curSum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

//这样子空间开销会比较大
class Solution {
public:
    //如果左节点不为空，且左节点没有左右孩子，那么这个节点就是左叶子
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> qu;
        if (root == NULL) return 0;
        qu.push(root);
        int result = 0;
        while (!qu.empty()) {
            TreeNode* node = qu.front();
            qu.pop();
            if (node->left != NULL && node->left->left == NULL && node->left->right == NULL) {
                result += node->left->val;
            }
            if (node->right) qu.push(node->right);
            if (node->left) qu.push(node->left);
        }
        return result;
    }
};