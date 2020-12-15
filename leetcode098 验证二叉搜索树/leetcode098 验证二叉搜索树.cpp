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
����һ�����������ж����Ƿ���һ����Ч�Ķ�����������
����һ��������������������������
�ڵ��������ֻ����С�ڵ�ǰ�ڵ������
�ڵ��������ֻ�������ڵ�ǰ�ڵ������
�������������������������Ҳ�Ƕ�����������
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
        //����������������������ϸ�ĵ�������
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
    TreeNode* pre = NULL; // ������¼ǰһ���ڵ� 
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        bool left = isValidBST(root->left);

        if (pre != NULL && pre->val >= root->val) return false;
        pre = root; // ��¼ǰһ���ڵ�

        bool right = isValidBST(root->right);
        return left && right;
    }
};

class Solution2 {
    //���õĲ����ǲ���ʼ����������߽ڵ��ʼ����Solution1
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