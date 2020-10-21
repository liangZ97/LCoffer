#include<iostream>
#include<vector>
#include<queue>
//#include<algorithm>
using namespace std;
struct TreeNode //在c++中struct和class除了默认访问权限不同，其余都相同
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) :val(v), left(NULL), right(NULL) {}
};
/*
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）
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
//层序遍历
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
//深度遍历
class DFS
{
public:
    //这里是递归遍历
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
    //下面是迭代方法
    vector<int> preordertraversal(TreeNode* node) {

    }
};

int main() {
    cout << "hello world" << endl;
    return 0;
}