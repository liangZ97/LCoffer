#include<iostream>
#include<vector>
using namespace std;
/*
����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֡�
���룺matrix = [[1,2,3],[4,5,6],[7,8,9]]
�����[1,2,3,6,9,8,7,4,5]
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /*�ж��Ƿ�Ϊ��*/
        if (matrix.size() == 0 || matrix[0].size() == 0) return {};
        /*�������������ĸ�����*/
        vector<int> res; /*�洢�������*/
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        /*���㷨ģ��˳ʱ������Ĺ��̣��������ӡ����*/
        while (true)
        {
            /*1.top�д����ұ���*/
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            /*top�ƶ�����һ�У������б߽���*/
            top++;
            if (top > bottom) break;

            /*2.right�д��ϵ��±���*/
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            /*right���ƣ������б߽���*/
            right--;
            if (right < left) break;

            /*3.bottom�д����������*/
            for (int i = right; i >= left; i--) {
                res.push_back(matrix[bottom][i]);
            }
            /*bottom�����ƣ������б߽���*/
            bottom--;
            if (bottom < top) break;
            /*4.left�д������ϱ���*/
            for (int i = bottom; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            /*left���ƣ������б߽���*/
            left++;
            if (left > right) break;
        }
        /*���ر������*/
        return res;
    }
};