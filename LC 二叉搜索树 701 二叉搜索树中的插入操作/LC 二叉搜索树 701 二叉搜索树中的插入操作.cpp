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
����������������BST���ĸ��ڵ��Ҫ�������е�ֵ����ֵ��������������� 
���ز��������������ĸ��ڵ㡣 �������� ��֤ ����ֵ��ԭʼ�����������е�����ڵ�ֵ����ͬ��
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