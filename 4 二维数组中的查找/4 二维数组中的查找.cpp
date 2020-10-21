/*
 ��һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������
 ÿһ�ж����մ��ϵ��µ�����˳�����������һ��������
 ����������һ����ά�����һ���������ж��������Ƿ��и�������
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) 
            return false;
        int rowSize = matrix.size();
        int columnSize = matrix[0].size();
        int row = 0;
        int column = columnSize - 1;
        /*
        ͬ���ģ������ķ������Ե���Ϊ�����½ǿ�ʼ������number<taaget����������++
        */
        //�����±��size-1��ʼ
        //�������Ͻ�Ԫ����Ϊ��־λ�ж�  =target
        //�������е�������              >target,��һ����С�ڵ�Ԫ�أ�����--�����ڲ���
        //                              <target,�������жϹ����ģ������ܴ���ƥ��Ԫ�ء�����һ�н����ж�
        while (row < rowSize && column >= 0 && !matrix.empty())
        {
            // �Ӿ�������Ͻǿ�ʼƥ�䣬���ƥ�䵽�ˣ�����true
            if (matrix[row][column] == target) return true;
            // ���ֵ��targetС����˵����һ�ж���targetС��row������һ��
            else if (matrix[row][column] < target) row++;
            // ���ֵ��target��˵����һ�ж���target��column������һ��
            else column--;
        }
        return false;
    }
};

//�����ǲ�������
int main() {
    vector<vector<int>> v = { {1, 4, 7, 11, 15},{2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30} };
    int target1 = 5;
    int target2 = 20;
    bool flag1=true;
    bool flag2=false;
    if (flag1 == Solution().findNumberIn2DArray(v, target1))
        cout << "test01 passed" << endl;
    else
        cout << "test01 failed" << endl;
    if (flag2 == Solution().findNumberIn2DArray(v, target2))
        cout << "test02 passed" << endl;
    else
        cout << "test02 failed" << endl;
    return 0;
}