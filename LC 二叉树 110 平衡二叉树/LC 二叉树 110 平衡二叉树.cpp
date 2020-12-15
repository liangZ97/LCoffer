#include<iostream>
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
����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
�����У�һ�ø߶�ƽ�����������Ϊ��һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��
*/

class Solution {
    int height(TreeNode* node) {
        if (!node)
            return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(rightHeight - leftHeight) > 1)
            return -1;
        else
            return max(leftHeight, rightHeight) + 1;
    }
public:
    //������뵽�Ե����ϵĵݹ鷨
    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};