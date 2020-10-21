#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
�����ĳ��Ʊ�ļ۸���ʱ���Ⱥ�˳��洢�������У����������ù�Ʊһ�ο��ܻ�õ���������Ƕ��٣�
����: [7,1,5,3,6,4]
���: 5
����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6-1 = 5 ��
     ע���������� 7-1 = 6, ��Ϊ�����۸���Ҫ��������۸�
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int max_salary = 0;
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            max_salary = max(max_salary, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return max_salary;
    }
};