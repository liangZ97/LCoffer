#include<iostream>
#include<vector>
#include<stack>
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
实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。
调用 next() 将返回二叉搜索树中的下一个最小的数。
next() 和 hasNext() 操作的时间复杂度是 O(1)，并使用 O(h) 内存，其中 h 是树的高度。
你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 中至少存在一个下一个最小的数。
*/

class BSTIterator {
    //得到二叉搜索树的中序遍历，然后再判断其是否越界判断hasNext()
    vector<int> res;
    int pos = 0;
    void inorder(TreeNode* root) {
        if (!root)
            return;
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }

    int next() {
        return res[pos++];
    }

    bool hasNext() {
        return pos < res.size();
    }
};

class BSTIterator {
    stack< TreeNode*> st;
    void leftOrder(TreeNode* root) {
        if (!root)
            return;
        st.push(root);
        leftOrder(root->left);
    }
public:
    BSTIterator(TreeNode* root) {
        leftOrder(root);
    }

    int next() {
        auto cur = st.top();
        st.pop();
        leftOrder(cur->right);
        return cur->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};
