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
����������������BST���ĸ��ڵ��һ��ֵ�� 
����Ҫ��BST���ҵ��ڵ�ֵ���ڸ���ֵ�Ľڵ㡣 
�����Ըýڵ�Ϊ���������� ����ڵ㲻���ڣ��򷵻� NULL��
*/

class Solution {
    //ʱ�临�Ӷ�/�ռ临�Ӷȣ�O(H)���ݹ�ջ�����Ϊ H��
    //ƽ����������Ϊ O(logN)�����������Ϊ O(N)��
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

//Ϊ�˽��Ϳռ临�Ӷȣ������ֶ����Ƶ�������
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