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
给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3
*/

//DFS，递归
class Solution {
    bool compare(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        return left->val == right->val && compare(left->left, right->right) && compare(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return compare(root->left, root->right);
    }
};

//迭代法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        queue< TreeNode*> qu;
        qu.push(root->left);
        qu.push(root->right);
        while (!qu.empty()){
            auto left = qu.front();
            qu.pop();
            auto right = qu.front();
            qu.pop();
            if (!left && !right)
                continue;
            if (!left || !right || left->val != right->val)
                return false;
            qu.push(left->left);
            qu.push(right->right);
            qu.push(left->right);
            qu.push(right->left);
        }
        return true;
    }
};