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
����һ�����������ҳ�����С��ȡ�
��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
˵����Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        queue< TreeNode*> qu;
        int depth = 0;
        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            ++depth;
            while (size--) {
                auto cur = qu.front();
                qu.pop();
                if (!cur->left && !cur->right) return depth;
                if (cur->left)
                    qu.push(cur->left);
                if (cur->right)
                    qu.push(cur->right);

            }
        }
        return depth;
    }
};
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        //Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
        //������������ڵ�Ϊ��ֱ�ӷ��أ���ô��һ��������Ϊ�յľ�ֱ�ӷ����ˣ�����
        if (!root->left && !root->right) return 1;

        int min_Depth = INT_MAX;
        if (root->left)
            min_Depth = min(min_Depth, minDepth(root->left));
        if (root->right)
            min_Depth = min(min_Depth, minDepth(root->right));
        return 1 + min_Depth;
    }
};