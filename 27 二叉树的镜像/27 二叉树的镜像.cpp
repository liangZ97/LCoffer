#include<iostream>
#include<stack>
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
请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：
     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：
     4
   /   \
  7     2
 / \   / \
9   6 3   1

*/
class Solution {
public:
    //其实就是翻转二叉树
    // TreeNode* mirrorTree(TreeNode* root) {
    //     //递归法
    //     if(!root) return root;//递归结束条件
    //     swap(root->left,root->right);
    //     if(root->left) mirrorTree(root->left);
    //     if(root->right) mirrorTree(root->right);
    //     return root;
    // }
    TreeNode* mirrorTree(TreeNode* root) {
        //迭代法，前序遍历交换左右子树
        if (!root) return root;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node) swap(node->left, node->right);
            else continue;
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return root;
    }
};