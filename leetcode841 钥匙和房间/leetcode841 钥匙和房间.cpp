#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
有 N 个房间，开始时你位于 0 号房间。
每个房间有不同的号码：0，1，2，...，N-1，并且房间里可能有一些钥匙能使你进入下一个房间。
在形式上，对于每个房间 i 都有一个钥匙列表 rooms[i]，
每个钥匙 rooms[i][j] 由 [0,1，...，N-1] 中的一个整数表示，
其中 N = rooms.length。 钥匙 rooms[i][j] = v 可以打开编号为 v 的房间。
最初，除 0 号房间外的其余所有房间都被锁住。
你可以自由地在房间之间来回走动。
如果能进入每个房间返回 true，否则返回 false。
*/

//DFS
class Solution {
    int nums = 0;
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int key) {
        if (visited[key])
            return;
        visited[key] = true;
        ++nums;
        for (auto& k : rooms[key])
            dfs(rooms, visited, k);
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if (!rooms.size())
            return true;
        vector<bool> visited(rooms.size());
        dfs(rooms, visited, 0);
        return nums == rooms.size();
    }
};

//BFS
class Solution1 {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if (!rooms.size())
            return true;
        vector<bool> visited(rooms.size());
        queue<int> qu;
        int nums = 0;
        qu.push(0);
        while (!qu.empty()) {
            int cur = qu.front();
            qu.pop();
            //要是不在这里再判断一下，要不提前将visited[0]置为true，否则会进入一次rooms[0]，造成nums++
            visited[cur] = true;
            ++nums;
            for (auto& key : rooms[cur]) {
                if (!visited[key]) {
                    qu.push(key);
                    visited[key] = true;
                }
            }
        }
        return nums == rooms.size();
    }
};


int main() {
    vector<vector<int>> rooms = { {1,3} ,{3,0,1},{2},{0} };
    bool res = Solution1().canVisitAllRooms(rooms);
    cout << res << endl;
    return 0;
}