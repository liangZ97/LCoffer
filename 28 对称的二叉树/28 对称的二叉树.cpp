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
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
    1
   / \
  2   2
   \   \
   3    3
*/
class Solution {
public:
    // bool isSymmetric(TreeNode* root) {
    //     if(!root) return true;
    //     return Compare(root->left,root->right);
    // }
    // bool Compare(TreeNode* left, TreeNode* right){
    //     //递归的结束条件
    //     if(!left&&!right) return true;
    //     if(!left||!right) return false;
    //     //递归的返回值
    //     return left->val==right->val&&Compare(left->left,right->right)&&Compare(left->right,right->left);
    // }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        //也可以利用队列先进先出特性
        stack<TreeNode*> st;
        st.push(root->right);
        st.push(root->left);
        while (!st.empty()) {
            TreeNode* left = st.top();
            st.pop();
            TreeNode* right = st.top();
            st.pop();
            if (!left && !right) continue;
            if (!left || !right || left->val != right->val) return false;
            st.push(left->left);
            st.push(right->right);
            st.push(left->right);
            st.push(right->left);
        }
        return true;
    }
};