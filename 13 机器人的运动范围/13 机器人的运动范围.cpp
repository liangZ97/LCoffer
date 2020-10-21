#include<iostream>
#include<vector>

using namespace std;
/*
������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��
һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ�����ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��
Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
���磬��kΪ18ʱ���������ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18��
�������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�
*/

class Solution {
public:
    int getSum(int x) {//�õ���λ֮��
        int sum = 0;
        for (; x; x /= 10) {
            sum += x % 10;
        }
        return sum;
    }
    int dfs(vector<vector<int>>& v, int m, int n, int rows, int columns, int k) {
        int sum = getSum(rows) + getSum(columns);
        //���ж��Ƿ����Խ��
        if (rows >= m || columns >= n || v[rows][columns] || sum > k) return 0;
        //��λ����ֹ�ظ�����
        v[rows][columns] = 1;
        //�����������������
        return 1 + dfs(v, m, n, rows + 1, columns, k) + dfs(v, m, n, rows, columns + 1, k);
    }
    int movingCount(int m, int n, int k) {
        //���������Ų�
        if (!m || !n) return 0;
        if (!k) return 1;
        //��ΪҪȷ��ÿ���ڵ��Ƿ���ʣ�����������ķ�ʽ��ʶ�Ƿ���б���
        vector<vector<int>> v(m, vector<int>(n, 0));
        return dfs(v, m, n, 0, 0, k);
    }
};
int main() {
    int m, n, k;
    m = 2;
    n = 3;
    k = 1;
    int res = 0;
    res = Solution().movingCount(m, n, k);
    cout << "result= " << res << endl;
    return 0;
}