#include<iostream>
#include<queue>
#include<sstream>
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
���л��ǽ�һ�����ݽṹ���߶���ת��Ϊ�����ı���λ�Ĳ�����
�������Խ�ת��������ݴ洢��һ���ļ������ڴ��У�
ͬʱҲ����ͨ�����紫�䵽��һ���������������ȡ�෴��ʽ�ع��õ�ԭ���ݡ�
�����һ���㷨��ʵ�ֶ����������л��뷴���л���
���ﲻ�޶�������� / �����л��㷨ִ���߼���
��ֻ��Ҫ��֤һ�����������Ա����л�Ϊһ���ַ������ҽ�����ַ��������л�Ϊԭʼ�����ṹ��
*/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        ostringstream out;
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            auto cur = qu.front();
            qu.pop();
            if (cur) {
                out << cur->val << " ";
                qu.push(cur->left);
                qu.push(cur->right);
            }
            else {
                out << "null ";
            }
        }
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (!data.size()) return nullptr;
        istringstream is(data);
        string str;
        vector<TreeNode*> res;
        while (is >> str) {
            if (str == "null")
                res.push_back(nullptr);
            else
                res.push_back(new TreeNode(stoi(str)));
        }
        //����
        int pos = 1;
        for (int i = 0; i < res.size(); ++i) {
            if (!res[i]) continue;
            //ע�������Ϊ��ÿ���ǿ�ָ���������������¼�����ˣ����Բ���������
            res[i]->left = res[pos++];
            //if (pos < res.size())
            res[i]->right = res[pos++];
        }
        return res[0];
    }
};


///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// * };
// */
//class Codec {
//public:
//
//    // Encodes a tree to a single string.
//    string serialize(TreeNode* root) {
//        if (!root) {
//            return ""; // �п�
//        }
//        ostringstream out;
//        queue<TreeNode*> bfs;
//        bfs.push(root);
//        while (!bfs.empty()) {
//            // ������
//            TreeNode* temp = bfs.front();
//            bfs.pop();
//            if (temp) {
//                out << temp->val << " ";
//                bfs.push(temp->left);
//                bfs.push(temp->right);
//            }
//            else {
//                out << "null "; // ע�� null �����пո�
//            }
//        }
//        return out.str(); // out ��������ת���ַ�����Ԫ��֮���ÿո�ָ�
//    }
//
//    // Decodes your encoded data to tree.
//    TreeNode* deserialize(string data) {
//        if (data.empty()) {
//            return nullptr; // �п�
//        }
//        istringstream input(data);
//        string info;
//        vector<TreeNode*> res; // res �������ַ�����ÿ��Ԫ��ת�� TreeNode* ��ʽ��Ԫ��
//        while (input >> info) {
//            if (info == "null") { // ע�� null ����û�ո���Ϊ�ո��������ָ��ַ����ģ��������ַ�����
//                res.push_back(nullptr);
//            }
//            else {
//                res.push_back(new TreeNode(stoi(info)));
//            }
//        }
//        int pos = 1;
//        for (int i = 0; pos < res.size(); ++i) {
//            // ��ѭ���� res �е�����Ԫ�������������һ�ö�����
//            if (!res[i]) {
//                continue;
//            }
//            res[i]->left = res[pos++]; // pos ��ʱָ����������++��ָ��������
//            if (pos < res.size()) {
//                res[i]->right = res[pos++]; // pos ��ʱָ����������++��ָ����һ���ڵ��������
//            }
//        }
//        return res[0];
//    }
//};
