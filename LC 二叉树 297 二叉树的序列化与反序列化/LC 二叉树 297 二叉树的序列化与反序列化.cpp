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
序列化是将一个数据结构或者对象转换为连续的比特位的操作，
进而可以将转换后的数据存储在一个文件或者内存中，
同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
请设计一个算法来实现二叉树的序列化与反序列化。
这里不限定你的序列 / 反序列化算法执行逻辑，
你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
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
        //连接
        int pos = 1;
        for (int i = 0; i < res.size(); ++i) {
            if (!res[i]) continue;
            //注意这里，因为将每个非空指针的左右子树都记录下来了，所以不会造成溢出
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
//            return ""; // 判空
//        }
//        ostringstream out;
//        queue<TreeNode*> bfs;
//        bfs.push(root);
//        while (!bfs.empty()) {
//            // 迭代法
//            TreeNode* temp = bfs.front();
//            bfs.pop();
//            if (temp) {
//                out << temp->val << " ";
//                bfs.push(temp->left);
//                bfs.push(temp->right);
//            }
//            else {
//                out << "null "; // 注意 null 后面有空格
//            }
//        }
//        return out.str(); // out 用来将树转成字符串，元素之间用空格分隔
//    }
//
//    // Decodes your encoded data to tree.
//    TreeNode* deserialize(string data) {
//        if (data.empty()) {
//            return nullptr; // 判空
//        }
//        istringstream input(data);
//        string info;
//        vector<TreeNode*> res; // res 用来将字符串里每个元素转成 TreeNode* 形式的元素
//        while (input >> info) {
//            if (info == "null") { // 注意 null 后面没空格（因为空格是用来分隔字符串的，不属于字符串）
//                res.push_back(nullptr);
//            }
//            else {
//                res.push_back(new TreeNode(stoi(info)));
//            }
//        }
//        int pos = 1;
//        for (int i = 0; pos < res.size(); ++i) {
//            // 本循环将 res 中的所有元素连起来，变成一棵二叉树
//            if (!res[i]) {
//                continue;
//            }
//            res[i]->left = res[pos++]; // pos 此时指向左子树，++后指向右子树
//            if (pos < res.size()) {
//                res[i]->right = res[pos++]; // pos 此时指向右子树，++后指向下一个节点的左子树
//            }
//        }
//        return res[0];
//    }
//};
