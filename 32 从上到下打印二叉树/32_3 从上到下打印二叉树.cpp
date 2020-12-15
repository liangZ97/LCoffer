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
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        //bool flag=true;
        int flag = 1;
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
            if ((flag++) & 1) res.push_back(vec);
            // if(flag) res.push_back(vec);
            else {
                reverse(vec.begin(), vec.end());
                res.push_back(vec);
            }
            // flag=!flag;
        }
        return res;
    }
};