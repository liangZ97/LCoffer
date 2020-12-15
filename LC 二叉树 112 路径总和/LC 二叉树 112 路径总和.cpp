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
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，
这条路径上所有节点值相加等于目标和。
说明: 叶子节点是指没有子节点的节点。
示例: 给定如下二叉树，以及目标和 sum = 22，
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
*/

//DFS
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        if (!root->left && !root->right)
            return sum - root->val == 0;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

class Solution {
    bool dfs(TreeNode* root, int sum) {
        if (!root)
            return false;
        if (!root->left && !root->right)
            return sum - root->val == 0;
        return dfs(root->left, sum - root->val) || dfs(root->right, sum - root->val);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        //if (!root->left && !root->right)
        //    return sum - root->val == 0;
        //return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
        return dfs(root, sum);
    }
};

//BFS
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        queue<TreeNode*> quTree;
        queue<int> quSum;
        quTree.push(root);
        quSum.push(root->val);
        while (!quTree.empty()) {
            auto cur = quTree.front();
            quTree.pop();
            auto curSum = quSum.front();
            quSum.pop();
            if (!cur->left && !cur->right) {
                //return sum == curSum; //这样碰到第一个分支直接返回了
                if (sum == curSum)
                    return true;
                continue;

            } 
            if (cur->left) {
                quTree.push(cur->left);
                quSum.push(cur->left->val + curSum);
            }
            if (cur->right) {
                quTree.push(cur->right);
                quSum.push(cur->right->val + curSum);
            }
            
        }
        return false;
    }
};