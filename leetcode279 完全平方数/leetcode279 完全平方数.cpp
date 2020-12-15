#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>
using namespace std;
/*
���������� n���ҵ����ɸ���ȫƽ���������� 1, 4, 9, 16, ...��ʹ�����ǵĺ͵��� n��
����Ҫ����ɺ͵���ȫƽ�����ĸ������١�
����: n = 12
���: 3
����: 12 = 4 + 4 + 4.
*/

class Solution {
public:
    /*����С��n��ƽ������: 1, 4, 9...*/
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
        vector<bool> visited(n + 1);    //��¼�ѷ��ʹ��Ľڵ�
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
                /*ÿ�ο�Խ�ļ��Ϊƽ����*/
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

//DP,�ؼ����ҵ����ƹ�ʽ��
//�����ǰ��������ֱ�ӳ�Ϊƽ�������϶�����ĳ��ƽ����A=B*B+C������C=D*D+E
//��ôҲ���ǵ�ǰ������һ����ʵҲ���ǹ۲�1~N-1˭����ȫƽ������С
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
