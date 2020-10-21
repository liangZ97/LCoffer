#include<iostream>
#include<vector>
#include<queue>
//#include<algorithm>
using namespace std;
struct TreeNode //��c++��struct��class����Ĭ�Ϸ���Ȩ�޲�ͬ�����඼��ͬ
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) :val(v), left(NULL), right(NULL) {}
};
/*
����һ�������������㷵���䰴 ������� �õ��Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩
    3
   / \
  9  20
    /  \
   15   7
  [
  [3],
  [9,20],
  [15,7]
  ]
*/
//�������
class BFS {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> result;
        if (root) qu.push(root);
        while (!qu.empty()) {
            vector<int> vec;
            int size = qu.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = qu.front();
                qu.pop();
                if (node) vec.push_back(node->val);
                else continue;
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};
//��ȱ���
class DFS
{
public:
    //�����ǵݹ����
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
    //�����ǵ�������
    vector<int> preordertraversal(TreeNode* node) {

    }
};

int main() {
    cout << "hello world" << endl;
    return 0;
}