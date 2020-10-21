#include<iostream>
#include<vector>

using namespace std;
/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
也不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
*/

class Solution {
public:
    int getSum(int x) {//得到数位之和
        int sum = 0;
        for (; x; x /= 10) {
            sum += x % 10;
        }
        return sum;
    }
    int dfs(vector<vector<int>>& v, int m, int n, int rows, int columns, int k) {
        int sum = getSum(rows) + getSum(columns);
        //先判断是否访问越界
        if (rows >= m || columns >= n || v[rows][columns] || sum > k) return 0;
        //置位，防止重复计算
        v[rows][columns] = 1;
        //向两个方向进行搜索
        return 1 + dfs(v, m, n, rows + 1, columns, k) + dfs(v, m, n, rows, columns + 1, k);
    }
    int movingCount(int m, int n, int k) {
        //进行意外排查
        if (!m || !n) return 0;
        if (!k) return 1;
        //因为要确定每个节点是否访问，所以用数组的方式标识是否进行遍历
        vector<vector<int>> v(m, vector<int>(n, 0));
        return dfs(v, m, n, 0, 0, k);
    }
};
int main() {
    int m, n, k;
    m = 2;
    n = 3;
    k = 1;
    int res = 0;
    res = Solution().movingCount(m, n, k);
    cout << "result= " << res << endl;
    return 0;
}