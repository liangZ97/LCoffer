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
����һ������������, �ҵ�����������ָ���ڵ������������ȡ�
�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q��
����������ȱ�ʾΪһ����� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //��Ϊ����������������ģ�����ֻ���ж���������Ϳ�����
        while (root) {
            if (root->val > p->val && root->val > q->val)
                root = root->left;
            else if (root->val < p->val && root->val < q->val)
                root = root->right;
            else
                return root;
        }
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        if (root->val > p->val && root->val > q->val) {
            auto left = lowestCommonAncestor(root->left, p, q);
            if (left)
                return left;
        }
        else if (root->val < p->val && root->val < q->val) {
            auto right = lowestCommonAncestor(root->right, p, q);
            if (right)
                return right;
        }
            return root;
    }
};
