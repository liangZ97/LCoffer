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
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明：叶子节点是指没有子节点的节点。
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
        //叶子节点是指没有子节点的节点。
        //如果像是求最大节点为空直接返回，那么第一个左子树为空的就直接返回了，错误。
        if (!root->left && !root->right) return 1;

        int min_Depth = INT_MAX;
        if (root->left)
            min_Depth = min(min_Depth, minDepth(root->left));
        if (root->right)
            min_Depth = min(min_Depth, minDepth(root->right));
        return 1 + min_Depth;
    }
};