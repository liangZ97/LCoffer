#include<iostream>
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
给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
*/

class Solution {
    int height(TreeNode* node) {
        if (!node)
            return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(rightHeight - leftHeight) > 1)
            return -1;
        else
            return max(leftHeight, rightHeight) + 1;
    }
public:
    //这个题想到自底向上的递归法
    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};