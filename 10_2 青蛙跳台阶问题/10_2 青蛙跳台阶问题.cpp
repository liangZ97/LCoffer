#include<iostream>
#include<ctime>
using namespace std;
/*
* һֻ����һ�ο�������1��̨�ף�Ҳ��������2��̨�ס������������һ�� n ����̨���ܹ��ж���������
*/
class Solution {
public:
    int numWays(int n) {
        //��Ϊ����һ��ֻ�ܱ�����̨�ף������ϵ�n��̨��ֻ��n-1��n-2�ַ�������ʵҲ������쳲���������
        if (n == 0 || n == 1)
            return 1;
        else {
            int a[2] = { 1,1 };//ע�����ﲻ�Ǵ�{0��1}��ʼ�����ģ���Ϊ����±����ȥ��0��쳲��������������±�
            for (int i = 2; i <= n; i++)
                a[i & 1] = (a[0] + a[1]) % (int)(1e9 + 7);
            return a[n & 1];
        }
    }
};

int main() {
    srand((unsigned int)time(NULL));
    int n = rand() % 101;
    cout << "n= " << n << endl;
    int numWays = Solution().numWays(n);
    cout << "numWays= " << numWays << endl;
    
    return 0;
}