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
给定一个二叉树的根节点 root ，返回它的 中序 遍历。
*/

//创新性思路是每次在栈中压入父节点后压入nullptr
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> st;
        vector<int> res;
        st.push(root);
        while (!st.empty()) {
            auto cur = st.top();
            if (cur != nullptr) {
                //非根节点
                st.pop();
                if (cur->right)
                    st.push(cur->right);
                st.push(cur);
                st.push(nullptr);
                if(cur->left)
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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> st;
        vector<int> res;
        //st.push(root);
        TreeNode* cur = root;
        while (!st.empty()||cur!=nullptr){
            if (cur) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                cur = st.top();
                st.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};


class Solution {
    void inorderTraversal(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inorderTraversal(root->left, res);
        res.push_back(root->val);
        inorderTraversal(root->right, res);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        inorderTraversal(root, res);
        return res;
    }
};