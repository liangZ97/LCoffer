#include<iostream>
#include<vector>
#include<stack>
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
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
*/

class Solution {
    void preorderTraversal(TreeNode* root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        preorderTraversal(root->left, res);
        preorderTraversal(root->right, res);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        preorderTraversal(root, res);
        return res;
    }
};


//迭代法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> st;
        vector<int> res;
        st.push(root);
        while (!st.empty()) {
            auto cur = st.top();
            st.pop();
            if (cur)
                res.push_back(cur->val);
            else
                continue;
            if (cur->right)
                st.push(cur->right);
            if (cur->left)
                st.push(cur->left);
        }
        return res;
    }
};