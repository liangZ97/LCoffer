#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>
using namespace std;
/*
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。
你需要让组成和的完全平方数的个数最少。
输入: n = 12
输出: 3
解释: 12 = 4 + 4 + 4.
*/

class Solution {
public:
    /*返回小于n的平方序列: 1, 4, 9...*/
    vector<int> getSquares(int n){
        vector<int> res;
        for (int i = 1; i * i <= n; ++i)
        {
            res.push_back(i * i);
        }
        return res;
    }
    int numSquares(int n)
    {
        vector<int> squares = getSquares(n);
        vector<bool> visited(n + 1);    //记录已访问过的节点
        queue<int> q;

        q.push(n);
        int res = 1;
        visited[n] = true;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int curr = q.front();
                q.pop();
                /*每次跨越的间隔为平方数*/
                for (int num : squares)
                {
                    int next = curr - num;
                    if (next < 0)
                    {
                        break;
                    }
                    if (next == 0)
                    {
                        return res;
                    }
                    if (visited[next])
                    {
                        continue;
                    }
                    visited[next] = true;
                    q.push(next);
                }
            }
            res++;
        }
        return n;
    }
};

//DP,关键是找到递推公式。
//如果当前的数不能直接成为平方数，肯定存在某个平方数A=B*B+C，其中C=D*D+E
//那么也就是当前步数加一。其实也就是观察1~N-1谁的完全平方数最小
class Solution {
public:
    int numSquares(int n){
        vector<int> res(n + 1, INT_MAX);
        res[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; i - j * j >= 0; ++j)
                res[i] = min(res[i], res[i - j * j] + 1);
        }
        return res[n];
    }
};
