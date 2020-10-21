#include<iostream>
using namespace std;
/*
ʹ��λ����Ķ�����������ӹ��̣�
1) ��������������λ��򣬵õ��޽�λ�ĺ� 
2) ����������λ�������ƣ������λ 
3) �޽�λ�����λ���
�ظ����������ֱ�������н�λ������λΪ0��
*/
class Solution {
public:
    int add(int a, int b) {
        int sum = 0, carry = 0;
        while (b) {
            //���a��b����ֵ����ͬ���������Ϊ1�����a��b����ֵ��ͬ�������Ϊ0��
            sum = a ^ b;
            carry = (unsigned int)(a & b) << 1;
            a = sum;
            b = carry;
        }
        return a;
    }
};
class Solution1 {
public:
    int add(int a, int b) {
        return b ? add(a ^ b, (unsigned int)(a & b) << 1) : a;
    }
};
/*
������⣺
 ��ʹ���µı�������������������ֵ����������������a��b��ϣ���������ǵ�ֵ�������ֲ�ͬ�Ĳ�����
 1. ���ڼӼ��� -- a = a + b; b = a - b; a = a - b;
 2. ����λ���� -- a = a ^ b; b = a ^ b; a = a ^ b;
*/
