#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
�㱻����һ�� m �� n �Ķ�ά�������������������ֿ��ܵĳ�ʼ��ֵ��
-1 ��ʾǽ�����ϰ���
0 ��ʾһ����
INF ���ޱ�ʾһ���յķ��䡣Ȼ�������� 2^31 - 1 = 2147483647 ���� INF��
�������Ϊͨ���ŵľ�������С�� 2147483647 �ġ�
��Ҫ��ÿ���շ���λ�����ϸ÷��䵽����ŵľ��룬����޷������ţ����� INF ���ɡ�
*/

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        //���Ǵ��ſ�ʼ���������������
        //���ڿ������������֤���������� d + 1 �����λ��ʱ�� ����Ϊ d ��λ�ö��Ѿ����������ˣ�
        //���Ե���ÿһ�������ʱ��һ������̾��롣
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
