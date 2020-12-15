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
给出一个完全二叉树，求出该树的节点个数。
完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其
余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。
若最底层为第 h 层，则该层包含 1~ 2h 个节点。
*/

class Solution {
    int getLeftHigth(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + getLeftHigth(root->left);
    }
    int getRightHigth(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + getRightHigth(root->right);
    }
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int leftHigth = getLeftHigth(root->left);
        int rightHigth = getRightHigth(root->right);

        int sum = 0;
        if (leftHigth == rightHigth) 
            sum = ((1 << leftHigth) - 1) << 1;
        else
            sum = countNodes(root->left) + countNodes(root->right);
        return sum + 1;
    }
};
