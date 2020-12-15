#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。两个相邻元素间的距离为 1 。
输入：
[[0,0,0],
 [0,1,0],
 [1,1,1]]
输出：
[[0,0,0],
 [0,1,0],
 [1,2,1]]
*/

//动态规划
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), INT_MAX / 2));
        //无论哪种更新方式都只能依赖两个前置状态
        //从左上到右下时， dp[i][j]只能依赖dp[i-1][j]和dp[i][j-1]
        //前面两种状态更新了
        
        //从左上到右下更新res
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j]) {
                    if (j - 1 >= 0)
                        res[i][j] = min(res[i][j], res[i][j - 1] + 1);
                    if (i - 1 >= 0)
                        res[i][j] = min(res[i][j], res[i - 1][j] + 1);
                }
                else
                    res[i][j] = 0;
            }
        }
        //右下到左上扫描
        for (int i = matrix.size() - 1; i >= 0; --i) {
            for (int j = matrix[0].size() - 1; j >= 0; --j) {
                if (matrix[i][j]) {
                    if (j + 1 < matrix[0].size())
                        res[i][j] = min(res[i][j], res[i][j + 1] + 1);
                    if (i + 1 < matrix.size())
                        res[i][j] = min(res[i][j], res[i + 1][j] + 1);
                }
                else
                    res[i][j] = 0;
            }
        }
        return res;
    }
};

//BFS
class Solution {
    int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size()));
        queue< pair<int, int >> qu;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (!matrix[i][j]) {
                    qu.push({ i, j });
                    visited[i][j] = 1;
                }
            }
        }
        while (!qu.empty()) {
            auto axis = qu.front();
            qu.pop();
            for (int i = 0; i < 4; ++i) {
                int r = axis.first + dir[i][0];
                int c = axis.second + dir[i][1];
                if (r >= 0 && r < matrix.size() && c >= 0 && c < matrix[0].size() && !visited[r][c]) {
                    res[r][c] = res[axis.first][axis.second] + 1;
                    qu.push({ r,c });
                    visited[r][c] = 1;
                }
            }
        }
        return res;
    }
};