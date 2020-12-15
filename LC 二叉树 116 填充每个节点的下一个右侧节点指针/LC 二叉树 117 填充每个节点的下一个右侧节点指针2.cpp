#include<iostream>
#include<queue>
#include<memory>
using namespace std;
struct Node {
	int val;
	Node* left;
	Node* right;
	Node* next;
};
/*
给定一个二叉树
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。
如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。
*/

//注意这里并不是完美二叉树

class Solution {
public:
	Node* connect(Node* root) {
		if (!root)
			return root;
		//如果第i层节点之间已经建立next指针，就可以通过next指针访问该层的所有节点
		//同时对于每个第i层的节点，我们又可以通过它的left和right指针知道其第i+1层的孩子节点是什么
		//所以遍历过程中就能够按顺序为第i+1层节点建立next指针。

		Node* cur = root;
		while (cur) {
			Node* dummy(new Node());
			Node* pre = dummy;
			while (cur) {
				if (cur->left) {
					pre->next = cur->left;
					pre = pre->next;
				}
				if (cur->right) {
					pre->next = cur->right;
					pre = pre->next;
				}
				cur = cur->next;
			}
			cur = dummy->next;
			delete dummy;
		}
		return root;
	}
};

//但是很明显，层序遍历是没问题的
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