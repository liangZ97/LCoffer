#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};
/*
根据一棵树的中序遍历与后序遍历构造二叉树。
注意:你可以假设树中没有重复的元素。
例如，给出:中序遍历 inorder = [9,3,15,20,7]。后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：
    3
   / \
  9  20
    /  \
   15   7
*/

class Solution {
    TreeNode* rebuildTree(vector<int>::iterator inBegin, vector<int>::iterator inEnd, vector<int>::iterator posBegin, vector<int>::iterator posEnd) {
        if (inBegin == inEnd)
            return nullptr;
        auto it = find(inBegin, inEnd, *(posEnd - 1));
        TreeNode* root = new TreeNode(*(posEnd - 1));
        root->left = rebuildTree(inBegin, it, posBegin, posBegin + (it - inBegin));
        root->right = rebuildTree(it+1, inEnd, posBegin + (it - inBegin), posEnd -1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //利用根节点一直分割得到左右子树
        //if (inorder.begin() == inorder.end())
        //    return nullptr;
        //TreeNode* root = new TreeNode(*(postorder.end() - 1));
        ////找到根节点所在的位置
        //auto it = find(inorder.begin(), inorder.end(), *(postorder.end() - 1));
        //vector<int>& inorderLeft(inorder.begin(), inorder.it);
        return rebuildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};