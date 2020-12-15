#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
�� N �����䣬��ʼʱ��λ�� 0 �ŷ��䡣
ÿ�������в�ͬ�ĺ��룺0��1��2��...��N-1�����ҷ����������һЩԿ����ʹ�������һ�����䡣
����ʽ�ϣ�����ÿ������ i ����һ��Կ���б� rooms[i]��
ÿ��Կ�� rooms[i][j] �� [0,1��...��N-1] �е�һ��������ʾ��
���� N = rooms.length�� Կ�� rooms[i][j] = v ���Դ򿪱��Ϊ v �ķ��䡣
������� 0 �ŷ�������������з��䶼����ס��
��������ɵ��ڷ���֮�������߶���
����ܽ���ÿ�����䷵�� true�����򷵻� false��
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
            //Ҫ�ǲ����������ж�һ�£�Ҫ����ǰ��visited[0]��Ϊtrue����������һ��rooms[0]�����nums++
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