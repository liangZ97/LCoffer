#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
��һ���Զ�ά���������ʾ��ͼ����ÿһ��������ʾ��ͼ��������ֵ��С����ֵ�� 0 �� 65535 ֮�䡣
����һ������ (sr, sc) ��ʾͼ����Ⱦ��ʼ������ֵ���� ���У���һ���µ���ɫֵ newColor������������ɫ���ͼ��
Ϊ�������ɫ�������ӳ�ʼ���꿪ʼ����¼��ʼ��������������ĸ�����������ֵ���ʼ������ͬ���������ص㣬
�����ټ�¼���ĸ������Ϸ������������ص������Ƕ�Ӧ�ĸ�����������ֵ���ʼ������ͬ���������ص㣬������
�ظ��ù��̡��������м�¼�����ص����ɫֵ��Ϊ�µ���ɫֵ��
��󷵻ؾ�����ɫ��Ⱦ���ͼ��
����:
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
���: [[2,2,2],[2,2,0],[2,0,1]]
*/
class Solution {
    void dfs(vector<vector<int>>& image, int sr, int sc, int& newColor, int& pexir) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != pexir)
            return;
        image[sr][sc] = newColor;
        dfs(image, sr + 1, sc, newColor, pexir);
        dfs(image, sr - 1, sc, newColor, pexir);
        dfs(image, sr, sc + 1, newColor, pexir);
        dfs(image, sr, sc - 1, newColor, pexir);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (!image.size() || !image[0].size())
            return{};
        int pexir = image[sr][sc];
        if (pexir == newColor)
            return image;
        //vector<vector<int>> res(image);
        //queue<pair<int, int>>  qu;
        dfs(image, sr, sc, newColor, pexir);
        return image;
    }
};

//BFS
class Solution1 {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (!image.size() || !image[0].size())
            return{};
        int pexir = image[sr][sc];
        if (pexir == newColor)
            return image;
        image[sr][sc] = newColor;
        //vector<pair<int, int>>  dirs = { {-1,0}, {1,0}, {0,-1}, {0,1} };
        queue<pair<int, int>>  qu;
        qu.push({ sr,sc });
        while (!qu.empty()) {
            int r = qu.front().first;
            int c = qu.front().second;
            qu.pop();
            if (r - 1 >= 0 && image[r - 1][c] == pexir) {
                qu.push({ r - 1,c });
                image[r - 1][c] = newColor;
            }
            if (r + 1 < image.size() && image[r + 1][c] == pexir) {
                qu.push({ r + 1,c });
                image[r + 1][c] = newColor;
            }
            if (c - 1 >= 0 && image[r][c - 1] == pexir) {
                qu.push({ r,c - 1 });
                image[r][c - 1] = newColor;
            }
            if (c + 1 < image[0].size() && image[r][c + 1] == pexir) {
                qu.push({ r,c + 1 });
                image[r][c + 1] = newColor;
            }
        }
        return image;
    }
};