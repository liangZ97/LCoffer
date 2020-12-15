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
给定一个二叉树，返回它的 后序 遍历。
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> st;
        vector<int> res;
        st.push(root);
        while (!st.empty()) {
            auto cur = st.top();
            if (cur != nullptr) {
                //非根节点
                st.pop();
                st.push(cur);
                st.push(nullptr);
                if (cur->right)
                    st.push(cur->right);
                if (cur->left)
                    st.push(cur->left);
            }
            else {
                //根节点
                st.pop();
                cur = st.top();
                st.pop();
                res.push_back(cur->val);
            }
        }
        return res;
    }
};


class Solution {
    void postorderTraversal(TreeNode* root, vector<int>& res) {
        if (!root) return;
        postorderTraversal(root->left, res);
        postorderTraversal(root->right, res);
        res.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        postorderTraversal(root, res);
        return res;
    }
};