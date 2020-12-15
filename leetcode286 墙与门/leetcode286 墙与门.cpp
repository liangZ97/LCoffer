#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
你被给定一个 m × n 的二维网格，网格中有以下三种可能的初始化值：
-1 表示墙或是障碍物
0 表示一扇门
INF 无限表示一个空的房间。然后，我们用 2^31 - 1 = 2147483647 代表 INF。
你可以认为通往门的距离总是小于 2147483647 的。
你要给每个空房间位上填上该房间到最近门的距离，如果无法到达门，则填 INF 即可。
*/

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        //我们从门开始做宽度优先搜索。
        //由于宽度优先搜索保证我们在搜索 d + 1 距离的位置时， 距离为 d 的位置都已经被搜索过了，
        //所以到达每一个房间的时候都一定是最短距离。
        if (rooms.empty() || rooms[0].empty()) return;
        const int INF = 2147483647;
        int m = rooms.size(), n = rooms[0].size();
        vector<pair<int, int>> directs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] != 0) continue;
                q.push(make_pair(i, j));
            }
        }
        while (!q.empty()) {
            auto pos = q.front(); q.pop();
            int x = pos.first, y = pos.second;
            //int dp = rooms[x][y] + 1;
            for (auto d : directs) {
                int nx = x + d.first, ny = y + d.second;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || rooms[nx][ny] != INF) 
                    continue;
                rooms[nx][ny] = rooms[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
        return;
    }
};
