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

����һ�������������ĸ��ڵ� root ��һ��ֵ key��
ɾ�������������е� key ��Ӧ�Ľڵ㣬����֤���������������ʲ��䡣
���ض������������п��ܱ����£��ĸ��ڵ�����á�
һ����˵��ɾ���ڵ�ɷ�Ϊ�������裺
�����ҵ���Ҫɾ���Ľڵ㣻
����ҵ��ˣ�ɾ������
˵���� Ҫ���㷨ʱ�临�Ӷ�Ϊ O(h)��h Ϊ���ĸ߶ȡ�
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
        //ȷ����������
        if (!root)
            return root;
        //����ݹ�
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right,key);
            return root;
        }

        //Ĭ��root->val==key
        //������������ýڵ������ҽڵ㣬�ýڵ�ֻ�����ҵ��ڵ㣬�ýڵ������ҽڵ�
        if (!root->left && !root->right) {
            root = nullptr;
        }
            
        else if (!root->left || !root->right) {
            auto temp = root;
            root = root->left ? root->left : root->right;
            delete temp;
        }
        else {
            //���ýڵ���ڵ�ӵ��ҽڵ���������ĵ�һ���ڵ�
            //Ҳ���ǽ���ڵ�ڵ��ҽڵ�����·�ȥ����֤������
            auto temp = root;
            root = root->right;
            auto cur = root;
            while (cur->left)
                cur = cur->left;
            cur->left = temp->left;
            //���ܸ���ָ��ָ��ֵ����������ָ����ȷ
            //Ҫ�ı�ָ��ͨ��->����Ҫ���ʵ��������ٸ�
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