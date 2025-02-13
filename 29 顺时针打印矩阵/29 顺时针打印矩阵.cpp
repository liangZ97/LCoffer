#include<iostream>
#include<vector>
using namespace std;
/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /*判断是否为空*/
        if (matrix.size() == 0 || matrix[0].size() == 0) return {};
        /*设置上下左右四个界限*/
        vector<int> res; /*存储遍历结果*/
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        /*此算法模拟顺时针输出的过程，请联想打印过程*/
        while (true)
        {
            /*1.top行从左到右遍历*/
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            /*top移动至下一行，并进行边界检测*/
            top++;
            if (top > bottom) break;

            /*2.right列从上到下遍历*/
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            /*right左移，并进行边界检测*/
            right--;
            if (right < left) break;

            /*3.bottom行从右往左遍历*/
            for (int i = right; i >= left; i--) {
                res.push_back(matrix[bottom][i]);
            }
            /*bottom行上移，并进行边界检测*/
            bottom--;
            if (bottom < top) break;
            /*4.left列从下往上遍历*/
            for (int i = bottom; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            /*left右移，并进行边界检测*/
            left++;
            if (left > right) break;
        }
        /*返回遍历结果*/
        return res;
    }
};