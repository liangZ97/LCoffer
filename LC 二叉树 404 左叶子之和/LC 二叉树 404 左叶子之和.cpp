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
���������������������Ҷ��֮�͡�
ʾ����
    3
   / \
  9  20
    /  \
   15   7

������������У���������Ҷ�ӣ��ֱ��� 9 �� 15�����Է��� 24
*/

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;
        //int leftSum = sumOfLeftLeaves(root->left);
        //int rightSum = sumOfLeftLeaves(root->right);

        int curSum = 0;
        if (root->left && !root->left->left && !root->left->right)
            curSum = root->left->val;
        return curSum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

//�����ӿռ俪����Ƚϴ�
class Solution {
public:
    //�����ڵ㲻Ϊ�գ�����ڵ�û�����Һ��ӣ���ô����ڵ������Ҷ��
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> qu;
        if (root == NULL) return 0;
        qu.push(root);
        int result = 0;
        while (!qu.empty()) {
            TreeNode* node = qu.front();
            qu.pop();
            if (node->left != NULL && node->left->left == NULL && node->left->right == NULL) {
                result += node->left->val;
            }
            if (node->right) qu.push(node->right);
            if (node->left) qu.push(node->left);
        }
        return result;
    }
};