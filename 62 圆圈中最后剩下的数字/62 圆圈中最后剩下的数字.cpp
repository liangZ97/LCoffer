#include<iostream>
#include<vector>
//#include<algorithm>
using namespace std;
/*
0,1,,n-1��n�������ų�һ��ԲȦ��������0��ʼ��ÿ�δ����ԲȦ��ɾ����m�����֡�
������ԲȦ��ʣ�µ����һ�����֡�
���磬0��1��2��3��4��5���������һ��ԲȦ��
������0��ʼÿ��ɾ����3�����֣���ɾ����ǰ4������������2��0��4��1��
������ʣ�µ�������3��
f(n,m) = [f(n-1, m) + m] % n  n>1
f(n,m) =0  n=1
*/

class Solution {
public:
    int lastRemaining(int n, int m) {
        int pos = 0;
        //��Ҫ����n-1��
        for (int i = 2; i <= n; i++) {
            pos = (pos + m) % i;
        }
        return pos;
    }
};