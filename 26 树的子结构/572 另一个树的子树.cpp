#include<iostream>
//#include<vector>
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
给定两个非空二叉树 s 和 t，
检验 s 中是否包含和 t 具有相同结构和节点值的子树。
s 的一个子树包括 s 的一个节点和这个节点的所有子孙。
s 也可以看做它自身的一棵子树。
*/
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        //找不到匹配的就报错
        if (!s) return false;
        return SubTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool SubTree(TreeNode* t1, TreeNode* t2) {
        if (!t1 || !t2) {
            if (t1 == t2) return true;
            else return false;
        }
        return t1->val == t2->val && SubTree(t1->left, t2->left) && SubTree(t1->right, t2->right);
    }
};