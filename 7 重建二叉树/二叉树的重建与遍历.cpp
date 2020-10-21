#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode //��c++��struct��class����Ĭ�Ϸ���Ȩ�޲�ͬ�����඼��ͬ
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
//�ݹ����
class RecursiveTraversal {
public:
	//void PreorderTraversal(TreeNode* node, vector<int>& result){}
	//ÿ�ֱ����ṩ�������أ�һ���÷���һ��vector������
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
		//ǰ�����&��������ȽϺ�д����Ϊ����˳��ʹ���˳����һ�µ�
		vector<int> result;
		stack<TreeNode*> st;
		if (node != NULL)
			st.push(node);
		while (!st.empty()) {
			TreeNode* root = st.top();
			st.pop();
			if (root != NULL)
				//�����ڵ�ֵ�ȷ���vector��
				result.push_back(root->val);
			else
				continue;
			//��Ϊ��ջ������ѹջ˳����ѹ����ѹ��
			st.push(root->right);
			st.push(root->left);
		}
		return result;
	}
	vector<int> InorderTraversal(TreeNode* node) {
		vector<int> result;
		stack<TreeNode*> st;
		//��Ϊ����˳��ʹ���˳��һ�£����Բ���ѹջ
		TreeNode* cur=node;
		while (cur != NULL || !st.empty()) {
			if (cur != NULL) {
				st.push(cur);
				//ֱ�����ʵ����²�ڵ�
				cur = cur->left;
			}
			else{				
				cur = st.top();
				st.pop();
				//��¼�ڵ�
				result.push_back(cur->val);
				//�л������ʸýڵ��������
				cur = cur->right;
			}
		}
		return result;
	}
	vector<int> PosorderTraversal(TreeNode* node) {
		//���ں����������Ϊ���ڵ�ŵ���������ڷ��ʸ��ڵ�ʱ��ֱ�Ӵ���
		//Ȼ��ı�����������ѹջ˳�����תvector����
		vector<int> result;
		stack<TreeNode*> st;
		if (node != NULL)
			st.push(node);
		while (!st.empty()) {//������->������->������
			TreeNode* root = st.top();
			st.pop();
			//��������or���ص��ж�����
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