#include<iostream>
//#include<vector>
//#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
/*
给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 
返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。
*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);
        if (root->val > val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);
        auto cur = root;
        while (cur) {
            if (cur->val > val) {
                if (!cur->left) {
                    cur->left = new TreeNode(val);
                    break;
                }
                else {
                    cur = cur->left;
                }
            }
            else {
                if (!cur->right) {
                    cur->right = new TreeNode(val);
                    break;
                }
                else {
                    cur = cur->right;
                }
            }
        }
        return root;
    }
};