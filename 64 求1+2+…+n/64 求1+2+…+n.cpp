#include<iostream>
using namespace std;
/*
�� 1+2+...+n ��Ҫ����ʹ��
�˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
����: n = 3
���: 6
*/

class Solution {
public:
    int sumNums(int n) {
        //1 <= n <= 10000
        //�ݹ�̫������
        /*
        ���ʹ�������ж����
        return n? n+sumNums(n-1):0;
        */

        //����ֻ�мӼ�������ֵ��λ������Լ��߼��������
        //���� && �� || �Ķ�·ЧӦ���еݹ�
        n && (n += sumNums(n - 1));
        return n;
    }
};