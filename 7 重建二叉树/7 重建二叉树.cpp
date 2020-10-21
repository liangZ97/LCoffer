#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    //���캯��
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    //���������ǰ�����������ǰ����������������������������������
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return ReconstructBinaryTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    //���õݹ飬���е��ж϶���������
    TreeNode* ReconstructBinaryTree(vector<int>::iterator preBegin, vector<int>::iterator preEnd,
        vector<int>::iterator inBegin, vector<int>::iterator inEnd) {
        //��������ǰ��Ҳ��������������н��������ж�
        if (preBegin == preEnd) return NULL;
        //�ȰѸ��ڵ㱣������������������ֿ�
        auto root = find(inBegin, inEnd, *preBegin);
        //��ӡ������ǰ�����
        //cout <<*root<< " ";
        TreeNode* cur = new TreeNode(*preBegin);
        //����������
        cur->left = ReconstructBinaryTree(preBegin + 1, preBegin + 1 + (root - inBegin), inBegin, root);
        //����������
        cur->right = ReconstructBinaryTree(preBegin + 1 + (root - inBegin), preEnd, root + 1, inEnd);
        //Ҫȷ����������������ȡ���ĸ��ڵ�
        return cur;
    }
};
class RecursiveTraversal {
public:
    void PreorderTraversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) 
            return;
        vec.push_back(cur->val);              // ��
        PreorderTraversal(cur->left, vec);    // ��
        PreorderTraversal(cur->right, vec);   // ��
    }
    void InorderTraversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) 
            return;     
        InorderTraversal(cur->left, vec);     // ��
        vec.push_back(cur->val);              // ��
        InorderTraversal(cur->right, vec);    // ��
    }
    void PostorderTraversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) 
            return;
        PostorderTraversal(cur->left, vec);   // ��
        PostorderTraversal(cur->right, vec);  // ��
        vec.push_back(cur->val);              // ��
    }
    
};
class IterativeTraversal {
public:
    vector<int> PreorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        st.push(root);
        //����˳��͵ݹ������
        while (!st.empty()) {
            TreeNode* node = st.top();                      // ��
            st.pop();
            if (node != NULL) 
                result.push_back(node->val);
            else 
                continue;                                   //ѹջ��Ҫ�ı�˳��
            st.push(node->right);                           // ��
            st.push(node->left);                            // ��
        }
        return result;
    }
    vector<int> InorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        //����˳��ͷ���˳���ǲ�һ�µ�
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // ָ�������ʽڵ㣬���ʵ���ײ�
                st.push(cur);  // �����ʵĽڵ�Ž�ջ
                cur = cur->left;                // ��
            }
            else {
                cur = st.top(); // ��ջ�ﵯ�������ݣ�����Ҫ��������ݣ��Ž�result����������ݣ�
                st.pop();
                result.push_back(cur->val);     // ��
                cur = cur->right;               // ��
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
            st.push(node->left); // �����ǰ������������һ����ջ˳��
            st.push(node->right);
        }
        reverse(result.begin(), result.end()); // �������ת֮����������е�˳����
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
    //�ֱ��õݹ鷨�͵���������������
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
