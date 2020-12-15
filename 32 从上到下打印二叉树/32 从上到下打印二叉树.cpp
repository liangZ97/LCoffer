#include<iostream>
#include<queue>
#include<vector>
//#include<algorithm>
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
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回：

[3,9,20,15,7]
*/

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        //层序遍历，利用队列先进先出，同一级进行遍历
        if (!root) return {};
        queue<TreeNode*> qu;
        vector<int> res;
        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = qu.front();
                qu.pop();
                if (node) res.push_back(node->val);
                else continue;
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }
        }
        return res;
    }
};