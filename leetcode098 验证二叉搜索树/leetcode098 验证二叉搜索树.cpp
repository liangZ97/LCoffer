#include<iostream>
#include<vector>
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
给定一个二叉树，判断其是否是一个有效的二叉搜索树。
假设一个二叉搜索树具有如下特征：
节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/

class Solution {
    vector<int> Inorder;
    void inorderTraversal(TreeNode* root) {
        if (!root) return;
        inorderTraversal(root->left);
        Inorder.push_back(root->val);
        inorderTraversal(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        Inorder.clear();
        //二叉搜索树的中序遍历是严格的递增数列
        inorderTraversal(root);
        for (int i = 1; i < Inorder.size(); ++i) {
            if (Inorder[i] <= Inorder[i - 1])
                return false;
        }
        return true;
    }
};

class Solution1 {
public:
    TreeNode* pre = NULL; // 用来记录前一个节点 
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        bool left = isValidBST(root->left);

        if (pre != NULL && pre->val >= root->val) return false;
        pre = root; // 记录前一个节点

        bool right = isValidBST(root->right);
        return left && right;
    }
};

class Solution2 {
    //更好的策略是不初始化，用最左边节点初始化。Solution1
    int pre = INT_MIN;
    bool DFS(TreeNode* node) {
        if (!node)
            return false;
        if (!DFS(node->left))
            return false;
        if (pre >= node->val)
            return false;
        pre = node->val;
        if (!DFS(node->right))
            return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return DFS(root);
    }
};