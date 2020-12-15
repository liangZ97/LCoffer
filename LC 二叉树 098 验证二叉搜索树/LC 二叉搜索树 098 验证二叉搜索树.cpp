#include<iostream>
#include<vector>
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
给定一个二叉树，判断其是否是一个有效的二叉搜索树。
假设一个二叉搜索树具有如下特征：
节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/

class Solution {
    //需要定义为全局变量，因为递归中都会用到
    TreeNode* pre = nullptr;
public:
    bool isValidBST(TreeNode* root) {
        //另外，可以用一个指针记录上一个节点，然后和上一个节点值进行比较
        //这样可以实现O(1)空间复杂度

        //依然是中序遍历
        if (!root)
            return true;
        bool left = isValidBST(root->left);

        if (pre && pre->val >= root->val)
            return false;
        pre = root;

        bool right = isValidBST(root->right);

        return left && right;
    }
};

class Solution {
    void inorder(TreeNode* root, vector<int>& inOrder) {
        if (!root)
            return;
        //if(root->left)
        inorder(root->left, inOrder);
        inOrder.push_back(root->val);
        inorder(root->right, inOrder);
    }
public: 
    bool isValidBST(TreeNode* root) {
        //首先，二叉搜索树中序遍历得到的必然是一个递增数组，我们可以得到这个数组然后判断其是否有序
        if (!root)
            return true;
        vector<int> inOrder;
        inorder(root, inOrder);

        for (int i = 1; i < inOrder.size(); ++i) {
            if (inOrder[i - 1] >= inOrder[i])
                return false;
        }
        return true;
    }
};
