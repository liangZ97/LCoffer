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
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
说明: 叶子节点是指没有子节点的节点。
示例:给定如下二叉树，以及目标和 sum = 22，
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:
[
   [5,4,11,2],
   [5,8,4,5]
]
*/
class Solution {
    vector<vector<int>> res;
    vector<int> path;
    void dfs(TreeNode* root, int sum) {
        if (!root)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == root->val)
                res.push_back(path);
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);//这里隐藏着回溯
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root)
            return {};
        dfs(root, sum);
        return res;
    }
};