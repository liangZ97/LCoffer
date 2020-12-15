#include<iostream>
#include<queue>
using namespace std;
struct Node {
	int val;
	Node* left;
	Node* right;
	Node* next;
};
/*
给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。
如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。

进阶：你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
*/

class Solution {
public:
	Node* connect(Node* root) {
		//一个很明显的思路是使用层序遍历
		if (!root)
			return root;
		queue< Node*> qu;
		qu.push(root);
		while (!qu.empty()) {
			auto size = qu.size();
			while (size--) {
				auto cur = qu.front();
				qu.pop();
				if (size)
					cur->next = qu.front();
				else
					cur->next = nullptr;
				if (cur->left)
					qu.push(cur->left);
				if (cur->right)
					qu.push(cur->right);
			}
		}
		return root;
	}
};

class Solution {
public:
	Node* connect(Node* root) {
		//但是使用栈就不满足O(1)的空间复杂度
		//可以的思路是左子树连接到右子树，右子树连接到根节点next的的左子树
		if (!root)
			return root;
		Node* cur = root;
		while (cur->left) {
			//cur控制层数 head控制该层结束
			auto head = cur;
			while (head) {
				head->left->next = head->right;
				if (head->next)
					head->right->next = head->next->left;
				head = head->next;
			}
			cur = cur->left;
		}
		return root;
	}
};
