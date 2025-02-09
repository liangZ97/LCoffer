#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。
给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像。
为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，
接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，……，
重复该过程。将所有有记录的像素点的颜色值改为新的颜色值。
最后返回经过上色渲染后的图像。
输入:
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
输出: [[2,2,2],[2,2,0],[2,0,1]]
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