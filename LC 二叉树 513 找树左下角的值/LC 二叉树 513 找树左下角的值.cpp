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
����һ�������������������һ���ҵ�����ߵ�ֵ��
*/

class Solution {
    int depth=INT_MIN;
    int leftVaule;
    void dfs(TreeNode* root,int curDepth) {
        if(!root->left&&!root->right){
            if (curDepth > depth) {
                depth = curDepth;
                leftVaule = root->val;
            }
            return;
        }
        if (root->left)
            dfs(root->left, curDepth + 1);
        if (root->right)
            dfs(root->right, curDepth + 1);

        return;
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        //�����Լ��������������ĸ��ڵ㣩��Ϊ NULL��
        //if (!root)
        //    return 0;
        dfs(root,0);
        return leftVaule;
    }
};