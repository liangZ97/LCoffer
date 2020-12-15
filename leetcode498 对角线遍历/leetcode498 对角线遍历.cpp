#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素。
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/diagonal_traverse.png
*/
//数组访问越界
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (!matrix.size()) return{};
        vector<int> res;
        //需要遍历的总次数为对角线和，即M+N-1
        int count = matrix.size() + matrix[0].size() - 1;
        int depth = matrix.size();
        int width = matrix[0].size();
        int row =0, colmun =0;
        //利用奇偶数区别从左到右和从右到左
        //int direction = 0;
        for (int direction = 0; direction < count; ++direction) {
            if (direction % 2 == 0) {
                //从左到右遍历，注意边界条件,上边界和右边界
                while (colmun < width && row >= 0) {
                    res.push_back(matrix[row][colmun]);
                    --row;
                    ++colmun;
                }
                //判断是由哪个边界出去的，校正参数
                if (colmun < width) {
                    row += 1;
                }
                else {
                    row += 2;
                    colmun -= 1;
                }
                //这样子为什么数组访问越界？？？
                //因为在左上方时候，此时上和右都越界，应该用右方修正，否则就会溢出
                //也就是说，这两个边界条件的修正优先级不同，优先修正右越界
                //垂直越界
                //if (row < 0) {
                //    row += 1;
                //}
                ////水平越界
                //else {
                //    row += 2;
                //    colmun -= 1;
                //}
            }
            else {
                //从右到左遍历，注意边界条件,下边界和左边界
                while (row < depth && colmun >= 0) {
                    res.push_back(matrix[row][colmun]);
                    ++row;
                    --colmun;
                }
                //水平越界
                if (row < depth) {
                    colmun += 1;
                }
                else {
                    row -= 1;
                    colmun += 2;
                }
                //同理在处理下越界时候，此时优先级高于左越界
                //if (colmun < 0) {
                //    colmun += 1;
                //}
                ////垂直越界
                //else {
                //    row -= 1;
                //    colmun += 2;
                //}
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
    vector<int> res;
    res = Solution().findDiagonalOrder(matrix);
    for (auto it = res.begin(); it != res.end(); ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}