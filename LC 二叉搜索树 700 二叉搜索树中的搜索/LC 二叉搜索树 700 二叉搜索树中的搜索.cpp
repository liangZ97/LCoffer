#include<iostream>
//#include<vector>
//#include<stack>
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
给定二叉搜索树（BST）的根节点和一个值。 
你需要在BST中找到节点值等于给定值的节点。 
返回以该节点为根的子树。 如果节点不存在，则返回 NULL。
*/

class Solution {
    //时间复杂度/空间复杂度：O(H)，递归栈的深度为 H。
    //平均情况下深度为 O(logN)，最坏情况下深度为 O(N)。
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        //if (!root)
        //    return nullptr;
        //if (root->val == val)
        //    return root;
        if(!root|| root->val == val)
            return root;
        else if (root->val > val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};

//为了降低空间复杂度，可以手动控制迭代方向
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
            return root;
        while (root && root->val != val) {
            root->val > val ? root = root->left : root = root->right;
        }
        return root;
    }
};