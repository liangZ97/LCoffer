#include<iostream>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};
/*
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
给定二叉树 [3,9,20,null,null,15,7]，
    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
*/

//DFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
};

//BFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
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
                if (cur->left)
                    qu.push(cur->left);
                if (cur->right)
                    qu.push(cur->right);

            }
        }
        return depth;
    }
};