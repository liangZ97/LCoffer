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
����һ��������������ÿ����㶼�����һ������ֵ��
�ҳ�·���͵��ڸ�����ֵ��·��������
·������Ҫ�Ӹ��ڵ㿪ʼ��Ҳ����Ҫ��Ҷ�ӽڵ����������·��������������µģ�ֻ�ܴӸ��ڵ㵽�ӽڵ㣩��
������������1000���ڵ㣬�ҽڵ���ֵ��Χ�� [-1000000,1000000] ��������
*/

class Solution {
    int res = 0;
    void dfs(TreeNode* root, int sum) {
        if (!root)
            return;
        sum -= root->val;
        if (sum == 0)
            ++res;
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return res;
        //if(!root->left&&!root->right)
        //·������Ҫ�Ӹ��ڵ㿪ʼ��Ҳ����Ҫ��Ҷ�ӽڵ����
        dfs(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return res;
    }
};

//class Solution {
//public:
//    bool hasPathSum(TreeNode* root, int sum) {
//        if (!root)
//            return false;
//        if (!root->left && !root->right)
//            return sum - root->val == 0;
//        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
//    }
//};
