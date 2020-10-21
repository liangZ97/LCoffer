#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
��n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs��
����n����ӡ��s�����п��ܵ�ֵ���ֵĸ��ʡ�
����Ҫ��һ�����������鷵�ش𰸣�
���е� i ��Ԫ�ش����� n ���������������ĵ��������е� i С���Ǹ��ĸ��ʡ�
����: 2
���: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
*/
class Solution {
public:
    vector<double> twoSum(int n) {
        //����һ�����鱣������״̬��һά�ǵ�n��ʱ����άΪ��n��ʱ���п������
        int dp[12][70] = { 0 };
        //dp[i][j]����ʾͶ����iö���Ӻ󣬵���j�ĳ��ִ���
        //����ֻ��֪����һ�ε������Ҳ�Ǳ߽�����
        for (int i = 1; i <= 6; i++)
        {
            //Ϊ�˿�������ֱ�ף���һ���˷���
            dp[1][i] = 1;
        }
        //��ʼ�������ӵ������ֵĴ���
        //��i������
        for (int i = 2; i <= n; ++i) {
            //i�����ӿ��ܳ��ֵĵ���
            for (int j = i; j <= n * 6; j++) {
                //������ֵĴ���
                for (int k = 1; k <= 6; k++) {
                    if (j - k < i - 1) break;
                    //��i��j����ֵĴ���ֻ������i-1�㣬j-(1-6)���ֵĴ�����
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        vector<double> res;
        int SumCount = pow(6, n);
        //ֻ��Ҫ������һ��
        for (int i = n; i <= n * 6; i++) {
            res.emplace_back((double)dp[n][i] * 1.0 / SumCount);
        }
        return res;
    }
};

//������ķ����У�����ֻ��������һ�㣬
//��������ܽ���ά����ת��Ϊһά����һ�����Լ�ܶ�Ŀռ俪��
class Solution1 {
public:
    vector<double> twoSum(int n) {
        //�����һά���飬��ôд���ݱ���Ҫ������д
        int dp[70] = { 0 };
        //���ó�ʼֵ����һ��1-6���ֵĴ�����Ϊһ��
        //Ϊ�˿��������㣬�����±��ʾ���Ӻ�ֵ
        for (int i = 1; i <= 6; ++i) {
            dp[i] = 1;
        }
        //���滹Ӧ��������ѭ��
        for (int count = 2; count <= n; ++count) {
            //����ÿ������һ�����ӣ������ܵĴ�С����д����
            for (int i = count * 6; i >= count; --i) {//forѭ������д���ܳ��ֵĵ����������ٶ�̬�滮����
                dp[i] = 0;//ע������Ҫ��������
                //����Ӵ��±������������break��Ϊcontinue��� 
                // for (int cur = 1; cur <= 6; ++cur)
                // {
                //     //��ʱ���ж�̬�滮
                //     if (i - cur < count - 1) break;//��֤����ֵ����Ϊ������
                //     //ע������dp[i]ԭ���п��ܲ�Ϊ�յ�
                //     dp[i] += dp[i - cur];
                // }
                for (int cur = 6; cur >= 1; --cur)
                {
                    //��ʱ���ж�̬�滮
                    //��֤����ֵ����Ϊ������
                    if (i - cur < count - 1) continue;
                    //ע������dp[i]ԭ���п��ܲ�Ϊ�յģ�����֮ǰҪ���
                    dp[i] += dp[i - cur];
                }
            }
        }
        vector<double> res;
        int SumCount = pow(6, n);
        for (int i = n; i <= n * 6; ++i) {
            res.emplace_back((double)dp[i] * 1.0 / SumCount);
        }
        return res;
    }
};