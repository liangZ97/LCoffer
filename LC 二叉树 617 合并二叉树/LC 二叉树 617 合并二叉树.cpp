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
给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，
那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。
输入:
	Tree 1                     Tree 2
		  1                         2
		 / \                       / \
		3   2                     1   3
	   /                           \   \
	  5                             4   7
输出:合并后的树:
		 3
		/ \
	   4   5
	  / \   \
	 5   4   7
*/

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		//单步递归结束条件
		if (!t1 && !t2)
			return nullptr;
		if (!t1 || !t2)
			return t1 ? t1 : t2;
		//前中后遍历都可以
		//直接利用t1立即修改
		t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);
		
		return t1;
	}
};


//迭代法
class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (!t1 && !t2)
			return nullptr;
		if (!t1 || !t2)
			return t1 ? t1 : t2;
		queue< TreeNode*> qu1;
		qu1.push(t1);
		queue< TreeNode*> qu2;
		qu2.push(t2);
		while (!qu1.empty() || !qu2.empty()) {
			auto cur1 = qu1.front(); qu1.pop();
			auto cur2 = qu2.front(); qu2.pop();
			cur1->val += cur2->val;

			if (cur1->left != NULL && cur2->left != NULL) {
				qu1.push(cur1->left);
				qu2.push(cur2->left);
			}
			// 如果两棵树右节点都不为空，加入队列
			if (cur1->right != NULL && cur2->right != NULL) {
				qu1.push(cur1->right);
				qu2.push(cur2->right);
			}

			// 当t1的左节点 为空 t2左节点不为空，就赋值过去
			if (cur1->left == NULL && cur2->left != NULL) {
				cur1->left = cur2->left;
			}
			// 当t1的右节点 为空 t2右节点不为空，就赋值过去
			if (cur1->right == NULL && cur2->right != NULL) {
				cur1->right = cur2->right;
			}
		}
		return t1;
	}
};