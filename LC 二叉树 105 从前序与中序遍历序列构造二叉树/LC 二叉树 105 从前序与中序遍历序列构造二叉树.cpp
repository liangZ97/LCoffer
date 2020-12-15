#include<iostream>
#include<vector>
#include<algorithm>
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
根据一棵树的前序遍历与中序遍历构造二叉树。
注意:你可以假设树中没有重复的元素。
例如，给出:前序遍历 preorder = [3,9,20,15,7].中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：
    3
   / \
  9  20
    /  \
   15   7
*/

class Solution {
    TreeNode* rebuildTree(vector<int>::iterator preBegin, vector<int>::iterator preEnd, vector<int>::iterator inBegin, vector<int>::iterator inEnd) {
        if (preBegin == preEnd)
            return nullptr;
        auto it = find(inBegin, inEnd, *preBegin);
        TreeNode* root = new TreeNode(*preBegin);
        root->left = rebuildTree(preBegin + 1, preBegin + 1 + (it - inBegin), inBegin, it);
        root->right = rebuildTree(preBegin + 1 + (it - inBegin), preEnd, it + 1, inEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return rebuildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};