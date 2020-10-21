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
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
B是A的子结构， 即 A中有出现和B相同的结构和节点值。
例如:
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。
*/
class Solution {
public:
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		//题目约定空树不是任何树的子结构
		if (!A || !B) return false;
		//bool res = false;
		//if (A->val == B->val) res=SubStructure(A, B);
		//这里进行了递归
		//if (!res) res = isSubStructure(A->left, B);
		//if (!res) res = isSubStructure(A->right, B);
		//if(A->val == B->val) return SubStructure(A, B) || isSubStructure(A->left, B) 
		//	                 || isSubStructure(A->right, B);
		//else return isSubStructure(A->left, B)|| isSubStructure(A->right, B);
		return SubStructure(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
	}
	bool SubStructure(TreeNode* t1, TreeNode* t2) {
		if (!t2) return true;//遍历到t2为空
		if (!t1) return false;//遍历完t1仍然未找到
		//if (t1->val != t2->val) return false;
		return t1->val == t2->val && SubStructure(t1->left, t2->left) && SubStructure(t1->right, t2->right);
	}
};