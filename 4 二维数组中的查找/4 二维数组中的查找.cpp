/*
 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，
 每一列都按照从上到下递增的顺序排序。请完成一个函数，
 输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) 
            return false;
        int rowSize = matrix.size();
        int columnSize = matrix[0].size();
        int row = 0;
        int column = columnSize - 1;
        /*
        同样的，遍历的方法可以调整为从左下角开始，遇到number<taaget，可以列数++
        */
        //列数下标从size-1开始
        //利用右上角元素作为标志位判断  =target
        //从上面行到下面行              >target,这一行有小于的元素，列数--，向内部走
        //                              <target,后面列判断过来的，不可能存在匹配元素。往下一行进行判断
        while (row < rowSize && column >= 0 && !matrix.empty())
        {
            // 从矩阵的右上角开始匹配，如果匹配到了，返回true
            if (matrix[row][column] == target) return true;
            // 如果值比target小，则说明这一行都比target小，row往下移一行
            else if (matrix[row][column] < target) row++;
            // 如果值比target大，说明这一列都比target大，column往左移一行
            else column--;
        }
        return false;
    }
};

//下面是测试用例
int main() {
    vector<vector<int>> v = { {1, 4, 7, 11, 15},{2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30} };
    int target1 = 5;
    int target2 = 20;
    bool flag1=true;
    bool flag2=false;
    if (flag1 == Solution().findNumberIn2DArray(v, target1))
        cout << "test01 passed" << endl;
    else
        cout << "test01 failed" << endl;
    if (flag2 == Solution().findNumberIn2DArray(v, target2))
        cout << "test02 passed" << endl;
    else
        cout << "test02 failed" << endl;
    return 0;
}