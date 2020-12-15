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
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
*/

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.size() < 2) return true;
        //分割区间寻找,后序遍历 左右中，先找到分割的节点
        return dfs(postorder, 0, postorder.size() - 1);
    }
    bool dfs(vector<int>& postorder, int left, int right) {
        //确定单步递归的条件
        if (left >= right) return true;
        //分离左右子树
        int count = 0;
        int BreakPoint = left;
        while (postorder[count] < postorder[right]) ++count;
        BreakPoint = count;
        //找到右子树第一个节点
        while (count < right) {
            if (postorder[count] <= postorder[right]) return false;
            ++count;
        }
        return dfs(postorder, left, BreakPoint - 1)
            && dfs(postorder, BreakPoint, right - 1);
    }
};