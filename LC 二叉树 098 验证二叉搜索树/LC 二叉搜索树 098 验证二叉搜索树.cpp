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
    //��Ҫ����Ϊȫ�ֱ�������Ϊ�ݹ��ж����õ�
    TreeNode* pre = nullptr;
public:
    bool isValidBST(TreeNode* root) {
        //���⣬������һ��ָ���¼��һ���ڵ㣬Ȼ�����һ���ڵ�ֵ���бȽ�
        //��������ʵ��O(1)�ռ临�Ӷ�

        //��Ȼ���������
        if (!root)
            return true;
        bool left = isValidBST(root->left);

        if (pre && pre->val >= root->val)
            return false;
        pre = root;

        bool right = isValidBST(root->right);

        return left && right;
    }
};

class Solution {
    void inorder(TreeNode* root, vector<int>& inOrder) {
        if (!root)
            return;
        //if(root->left)
        inorder(root->left, inOrder);
        inOrder.push_back(root->val);
        inorder(root->right, inOrder);
    }
public: 
    bool isValidBST(TreeNode* root) {
        //���ȣ�������������������õ��ı�Ȼ��һ���������飬���ǿ��Եõ��������Ȼ���ж����Ƿ�����
        if (!root)
            return true;
        vector<int> inOrder;
        inorder(root, inOrder);

        for (int i = 1; i < inOrder.size(); ++i) {
            if (inOrder[i - 1] >= inOrder[i])
                return false;
        }
        return true;
    }
};
