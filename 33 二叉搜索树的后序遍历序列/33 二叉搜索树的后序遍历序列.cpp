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
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�����������
������򷵻� true�����򷵻� false���������������������������ֶ�������ͬ��
*/

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.size() < 2) return true;
        //�ָ�����Ѱ��,������� �����У����ҵ��ָ�Ľڵ�
        return dfs(postorder, 0, postorder.size() - 1);
    }
    bool dfs(vector<int>& postorder, int left, int right) {
        //ȷ�������ݹ������
        if (left >= right) return true;
        //������������
        int count = 0;
        int BreakPoint = left;
        while (postorder[count] < postorder[right]) ++count;
        BreakPoint = count;
        //�ҵ���������һ���ڵ�
        while (count < right) {
            if (postorder[count] <= postorder[right]) return false;
            ++count;
        }
        return dfs(postorder, left, BreakPoint - 1)
            && dfs(postorder, BreakPoint, right - 1);
    }
};