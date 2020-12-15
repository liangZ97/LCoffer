#include<iostream>
#include<queue>
#include<vector>
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
���ϵ��°����ӡ��������ͬһ��Ľڵ㰴�����ҵ�˳���ӡ��ÿһ���ӡ��һ�С�
*/

//��ȱ���
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            vector<int> vec;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = qu.front();
                qu.pop();
                if (node) vec.push_back(node->val);
                else continue;
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};