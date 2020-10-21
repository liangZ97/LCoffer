#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    //构造函数
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    //给出中序和前序遍历，根据前序遍历将中序遍历的左子树和右子树分离
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return ReconstructBinaryTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    //利用递归，所有的判断都在里面做
    TreeNode* ReconstructBinaryTree(vector<int>::iterator preBegin, vector<int>::iterator preEnd,
        vector<int>::iterator inBegin, vector<int>::iterator inEnd) {
        //可以利用前序，也可以利用中序进行结束条件判断
        if (preBegin == preEnd) return NULL;
        //先把根节点保存下来，将中序遍历分开
        auto root = find(inBegin, inEnd, *preBegin);
        //打印出来是前序遍历
        //cout <<*root<< " ";
        TreeNode* cur = new TreeNode(*preBegin);
        //左子树分离
        cur->left = ReconstructBinaryTree(preBegin + 1, preBegin + 1 + (root - inBegin), inBegin, root);
        //右子树分离
        cur->right = ReconstructBinaryTree(preBegin + 1 + (root - inBegin), preEnd, root + 1, inEnd);
        //要确定左右子树不包含取出的根节点
        return cur;
    }
};
class RecursiveTraversal {
public:
    void PreorderTraversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) 
            return;
        vec.push_back(cur->val);              // 中
        PreorderTraversal(cur->left, vec);    // 左
        PreorderTraversal(cur->right, vec);   // 右
    }
    void InorderTraversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) 
            return;     
        InorderTraversal(cur->left, vec);     // 左
        vec.push_back(cur->val);              // 中
        InorderTraversal(cur->right, vec);    // 右
    }
    void PostorderTraversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) 
            return;
        PostorderTraversal(cur->left, vec);   // 左
        PostorderTraversal(cur->right, vec);  // 右
        vec.push_back(cur->val);              // 中
    }
    
};
class IterativeTraversal {
public:
    vector<int> PreorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        st.push(root);
        //整个顺序和递归很相似
        while (!st.empty()) {
            TreeNode* node = st.top();                      // 中
            st.pop();
            if (node != NULL) 
                result.push_back(node->val);
            else 
                continue;                                   //压栈，要改变顺序
            st.push(node->right);                           // 右
            st.push(node->left);                            // 左
        }
        return result;
    }
    vector<int> InorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        //处理顺序和访问顺序是不一致的
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                st.push(cur);  // 将访问的节点放进栈
                cur = cur->left;                // 左
            }
            else {
                cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                st.pop();
                result.push_back(cur->val);     // 中
                cur = cur->right;               // 右
            }
        }
        return result;
    }
    vector<int> PostorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node != NULL) 
                result.push_back(node->val);
            else 
                continue;
            st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序
            st.push(node->right);
        }
        reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
        return result;
    }
};


int main() {
    vector<int> preorder = { 3,9,20,15,7 };
    vector<int> inorder  = { 9,3,15,20,7 };
    vector<int> posorder = { 9,15,7,20,3 };
    vector<int> recursivetraversal;
    vector<int> iterativetraversal;
    TreeNode* RebuildBinaryTree = Solution().buildTree(preorder, inorder);
    //分别用递归法和迭代法遍历二叉树
    RecursiveTraversal().PreorderTraversal(RebuildBinaryTree, recursivetraversal);
    iterativetraversal=IterativeTraversal().PreorderTraversal(RebuildBinaryTree);
    cout << "PreorderTraversal is " << endl;
    for (int i = 0; i < recursivetraversal.size(); i++) {
        cout << recursivetraversal[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < recursivetraversal.size(); i++) {
        cout << recursivetraversal[i] << " ";
    }
    cout << endl;
    if (recursivetraversal == preorder&& iterativetraversal == preorder)
        cout << "PreorderTraversal test passed " << endl;
    else
        cout << "PreorderTraversal test failed " << endl;
    cout << "-------------------------------------" << endl;
    recursivetraversal.clear();
    iterativetraversal.clear();
    RecursiveTraversal().InorderTraversal(RebuildBinaryTree, recursivetraversal);
    iterativetraversal = IterativeTraversal().InorderTraversal(RebuildBinaryTree);
    cout << "InorderTraversal is " << endl;
    for (int i = 0; i < recursivetraversal.size(); i++) {
        cout << recursivetraversal[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < iterativetraversal.size(); i++) {
        cout << iterativetraversal[i] << " ";
    }
    cout << endl;
    if (recursivetraversal == inorder && iterativetraversal == inorder)
        cout << "InorderTraversal test passed " << endl;
    else
        cout << "InorderTraversal test failed " << endl;
    cout << "-------------------------------------" << endl;
    recursivetraversal.clear();
    iterativetraversal.clear();
    RecursiveTraversal().PostorderTraversal(RebuildBinaryTree, recursivetraversal);
    iterativetraversal = IterativeTraversal().PostorderTraversal(RebuildBinaryTree);
    cout << "PostorderTraversal is " << endl;
    for (vector<int>::iterator it = recursivetraversal.begin(); it != recursivetraversal.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    for (int i = 0; i < iterativetraversal.size(); i++) {
        cout << iterativetraversal[i] << " ";
    }
    cout << endl;
    if(recursivetraversal == posorder && iterativetraversal == posorder)
        cout << "PreorderTraversal test passed " << endl;
    else
    cout << "PreorderTraversal test failed " << endl;
    cout << "-------------------------------------" << endl;
    recursivetraversal.clear();
    iterativetraversal.clear();
    return 0;
}
