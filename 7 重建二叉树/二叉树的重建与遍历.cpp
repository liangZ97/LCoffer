#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode //在c++中struct和class除了默认访问权限不同，其余都相同
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) :val(v), left(NULL), right(NULL) {}
};

class BuildTree {
public:
	TreeNode* buildTree(vector<int>&preorder, vector<int>& inorder) {
		return ReconstructBinaryTree(preorder.begin(),preorder.end(), inorder.begin(), inorder.end());
	}
	TreeNode* ReconstructBinaryTree(vector<int>::iterator prebegin, vector<int>::iterator preend,
		vector<int>::iterator inbegin, vector<int>::iterator inend) {
		if (prebegin == preend)
			return NULL;
		TreeNode* cur = new TreeNode(*prebegin);
		auto root=find(inbegin, inend, cur);
		cur->left = ReconstructBinaryTree(prebegin+1,prebegin+1+(root-inbegin),inbegin,root);
		cur->right = ReconstructBinaryTree(prebegin + 1 + (root - inbegin),preend,root + 1, inend);
		return cur;
	}
};
//递归遍历
class RecursiveTraversal {
public:
	//void PreorderTraversal(TreeNode* node, vector<int>& result){}
	//每种遍历提供两种重载，一般用返回一个vector的这种
	vector<int> PreorderTraversal(TreeNode* node) {
		vector<int> result;
		PreorderTraversal(node, result);
		return result;
	}
	void PreorderTraversal(TreeNode* node, vector<int>& result) {
		if (node == NULL)
			return;
		result.push_back(node->val);
		PreorderTraversal(node->left, result);
		PreorderTraversal(node->right, result);
	}
	vector<int> InorderTraversal(TreeNode* node){
		vector<int> result;
		InorderTraversal(node, result);
		return result;
	}
	void InorderTraversal(TreeNode* node, vector<int>& result) {
		if (node == NULL)
			return;
		InorderTraversal(node->left, result);
		result.push_back(node->val);
		InorderTraversal(node->right, result);
	}
	vector<int> PosorderTraversal(TreeNode* node) {
		vector<int> result;
		PosorderTraversal(node, result);
		return result;
	}
	void PosorderTraversal(TreeNode* node, vector<int>& result) {
		if (node == NULL)
			return;
		PosorderTraversal(node->left, result);
		PosorderTraversal(node->right, result);
		result.push_back(node->val);
	}
};

class IterativeTraversal {
	vector<int> PreorderTraversal(TreeNode* node) {
		//前序遍历&后序遍历比较好写，因为访问顺序和处理顺序是一致的
		vector<int> result;
		stack<TreeNode*> st;
		if (node != NULL)
			st.push(node);
		while (!st.empty()) {
			TreeNode* root = st.top();
			st.pop();
			if (root != NULL)
				//将本节点值先放入vector中
				result.push_back(root->val);
			else
				continue;
			//因为是栈，所以压栈顺序先压右再压左
			st.push(root->right);
			st.push(root->left);
		}
		return result;
	}
	vector<int> InorderTraversal(TreeNode* node) {
		vector<int> result;
		stack<TreeNode*> st;
		//因为访问顺序和处理顺序不一致，所以不能压栈
		TreeNode* cur=node;
		while (cur != NULL || !st.empty()) {
			if (cur != NULL) {
				st.push(cur);
				//直到访问到最下层节点
				cur = cur->left;
			}
			else{				
				cur = st.top();
				st.pop();
				//记录节点
				result.push_back(cur->val);
				//切换到访问该节点的右子树
				cur = cur->right;
			}
		}
		return result;
	}
	vector<int> PosorderTraversal(TreeNode* node) {
		//对于后序遍历，因为根节点放到最后，所以在访问根节点时候直接处理，
		//然后改变左右子树的压栈顺序，最后反转vector即可
		vector<int> result;
		stack<TreeNode*> st;
		if (node != NULL)
			st.push(node);
		while (!st.empty()) {//左右中->中右左->中左右
			TreeNode* root = st.top();
			st.pop();
			//继续搜素or返回的判断条件
			if (root != NULL)
				result.push_back(root->val);
			else
				continue;
			st.push(root->left);
			st.push(root->right);
		}
		return result;
	}
};

int main() {
	vector<int> preorder = { 3,9,20,15,7 };
	vector<int> inorder = { 9,3,15,20,7 };
	vector<int> recursivetraversal;
	TreeNode* ReBuildBT = BuildTree().buildTree(preorder, inorder);
	recursivetraversal = RecursiveTraversal().PreorderTraversal(ReBuildBT);
	for (int i = 0; i < recursivetraversal.size(); i++) {
		cout << recursivetraversal[i] << " ";
	}
	cout << endl;
	if (recursivetraversal == preorder)
		cout << "PreorderTraversal test passed " << endl;
	else
		cout << "PreorderTraversal test failed " << endl;
	return 0;
}