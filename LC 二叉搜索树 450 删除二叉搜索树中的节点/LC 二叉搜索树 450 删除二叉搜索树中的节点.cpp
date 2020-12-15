#include<iostream>
#include<queue>
#include<sstream>
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

给定一个二叉搜索树的根节点 root 和一个值 key，
删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。
返回二叉搜索树（有可能被更新）的根节点的引用。
一般来说，删除节点可分为两个步骤：
首先找到需要删除的节点；
如果找到了，删除它。
说明： 要求算法时间复杂度为 O(h)，h 为树的高度。
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> st;
        vector<int> res;
        st.push(root);
        while (!st.empty()) {
            auto cur = st.top();
            st.pop();
            if (cur)
                res.push_back(cur->val);
            else
                continue;
            if (cur->right)
                st.push(cur->right);
            if (cur->left)
                st.push(cur->left);
        }
        return res;
    }
    TreeNode* deserialize(string data) {
        stringstream s(data);
        string str_node;
        queue<TreeNode*> que;
        getline(s, str_node, ',');
        TreeNode* root;
        if (str_node == "nullptr") {
            return nullptr;
        }
        else {
            int inte_node = stoi(str_node);
            root = new TreeNode(inte_node);
            que.push(root);
        }
        while (!que.empty()) {
            int siz = que.size();
            while (siz--) {
                TreeNode* cur = que.front();
                que.pop();
                if (cur != nullptr) {
                    string str_left, str_right;
                    if (getline(s, str_left, ',') && str_left != "nullptr") {
                        TreeNode* l = new TreeNode(stoi(str_left));
                        que.push(l);
                        cur->left = l;
                    }
                    if (getline(s, str_right, ',') && str_right != "nullptr") {
                        TreeNode* r = new TreeNode(stoi(str_right));
                        que.push(r);
                        cur->right = r;
                    }
                }
            }
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //确定结束条件
        if (!root)
            return root;
        //单层递归
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right,key);
            return root;
        }

        //默认root->val==key
        //分三种情况：该节点无左右节点，该节点只有左右单节点，该节点有左右节点
        if (!root->left && !root->right) {
            root = nullptr;
        }
            
        else if (!root->left || !root->right) {
            auto temp = root;
            root = root->left ? root->left : root->right;
            delete temp;
        }
        else {
            //将该节点左节点接到右节点中序遍历的第一个节点
            //也就是将左节点节点右节点的左下方去，保证有序性
            auto temp = root;
            root = root->right;
            auto cur = root;
            while (cur->left)
                cur = cur->left;
            cur->left = temp->left;
            //不能给空指针指定值，否则会出现指向不正确
            //要改变指向通过->，不要访问到这里了再改
             //while(cur){
             //    cur=cur->left;
             //}
             //cur=temp->left;
            delete temp;
        }
        return root;
    }
};

int main() {
    string data = "5,3,6,2,4,nullptr,7";
    int key = 3;
    TreeNode* Tree = Solution().deserialize(data);
    TreeNode* newTree = Solution().deleteNode(Tree, key);
    vector<int> preOrder = Solution().preorderTraversal(newTree);
    for (int i = 0; i < preOrder.size(); ++i)
        cout << preOrder[i] << " ";
    cout << endl;
    return 0;
}