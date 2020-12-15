#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������
�������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�����/����ֱ���������ڵ�½�������γɡ�
���⣬����Լ��������������߾���ˮ��Χ��
���룺grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
�����3
*/

//�����������Ѱ��·�����⣨��ָoffer12��Ѱ�Ҿ����е�·����������ʹ��BFS��DFS
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

//BFS,�Ȱ�'1'��ӣ��ĸ������ַ�����
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
                    //��֤�����ظ�·
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
