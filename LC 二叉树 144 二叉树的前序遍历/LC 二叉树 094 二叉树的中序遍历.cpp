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
����һ���������ĸ��ڵ� root ���������� ���� ������
*/

//������˼·��ÿ����ջ��ѹ�븸�ڵ��ѹ��nullptr
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
                //�Ǹ��ڵ�
                st.pop();
                if (cur->right)
                    st.push(cur->right);
                st.push(cur);
                st.push(nullptr);
                if(cur->left)
                    st.push(cur->left);
            }
            else {
                //���ڵ�
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