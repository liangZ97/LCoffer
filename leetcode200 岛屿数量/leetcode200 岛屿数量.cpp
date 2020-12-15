#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
*/

//这个题类似于寻找路径的题（剑指offer12，寻找矩阵中的路径），可以使用BFS和DFS
class Solution {
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != '1')
            return;
        grid[r][c] = '0';
        if (r - 1 >= 0)
            dfs(grid, r - 1, c);
        if (r + 1 < grid.size())
            dfs(grid, r + 1, c);
        if (c+1 >= 0)
            dfs(grid, r, c + 1);
        if (c-1 < grid[0].size())
            dfs(grid, r, c - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        size_t rows = grid.size();
        size_t columns = grid[0].size();
        int nums = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j)
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++nums;
                }

        }
        return nums;
    }
};

//BFS,先把'1'入队，四个方向轮番搜索
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        size_t rows = grid.size();
        size_t columns = grid[0].size();
        int nums = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (grid[i][j] == '1') {
                    nums++;
                    //保证不走重复路
                    grid[i][j] = '0';
                    queue<pair<int, int>> qu;
                    qu.push({ i,j });
                    while (!qu.empty()) {
                        int r = qu.front().first;
                        int c = qu.front().second;
                        qu.pop();
                        if (r - 1 >= 0 && grid[r - 1][c] == '1') {
                            qu.push({ r - 1,c });
                            grid[r - 1][c] = '0';
                        }
                        if (r + 1 < grid.size() && grid[r + 1][c] == '1') {
                            qu.push({ r + 1,c });
                            grid[r + 1][c] = '0';
                        }
                        if (c - 1 >= 0 && grid[r][c - 1] == '1') {
                            qu.push({ r,c - 1 });
                            grid[r][c - 1] = '0';
                        }
                        if (c + 1 < grid[0].size() && grid[r][c + 1] == '1') {
                            qu.push({ r,c+1 });
                            grid[r][c+1] = '0';
                        }
                    }
                }
            }
        }
        return nums;
    }
};
