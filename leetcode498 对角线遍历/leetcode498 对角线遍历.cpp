#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
����һ������ M x N ��Ԫ�صľ���M �У�N �У������ԶԽ��߱�����˳�򷵻���������е�����Ԫ�ء�
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/diagonal_traverse.png
*/
//�������Խ��
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (!matrix.size()) return{};
        vector<int> res;
        //��Ҫ�������ܴ���Ϊ�Խ��ߺͣ���M+N-1
        int count = matrix.size() + matrix[0].size() - 1;
        int depth = matrix.size();
        int width = matrix[0].size();
        int row =0, colmun =0;
        //������ż����������Һʹ��ҵ���
        //int direction = 0;
        for (int direction = 0; direction < count; ++direction) {
            if (direction % 2 == 0) {
                //�����ұ�����ע��߽�����,�ϱ߽���ұ߽�
                while (colmun < width && row >= 0) {
                    res.push_back(matrix[row][colmun]);
                    --row;
                    ++colmun;
                }
                //�ж������ĸ��߽��ȥ�ģ�У������
                if (colmun < width) {
                    row += 1;
                }
                else {
                    row += 2;
                    colmun -= 1;
                }
                //������Ϊʲô�������Խ�磿����
                //��Ϊ�����Ϸ�ʱ�򣬴�ʱ�Ϻ��Ҷ�Խ�磬Ӧ�����ҷ�����������ͻ����
                //Ҳ����˵���������߽��������������ȼ���ͬ������������Խ��
                //��ֱԽ��
                //if (row < 0) {
                //    row += 1;
                //}
                ////ˮƽԽ��
                //else {
                //    row += 2;
                //    colmun -= 1;
                //}
            }
            else {
                //���ҵ��������ע��߽�����,�±߽����߽�
                while (row < depth && colmun >= 0) {
                    res.push_back(matrix[row][colmun]);
                    ++row;
                    --colmun;
                }
                //ˮƽԽ��
                if (row < depth) {
                    colmun += 1;
                }
                else {
                    row -= 1;
                    colmun += 2;
                }
                //ͬ���ڴ�����Խ��ʱ�򣬴�ʱ���ȼ�������Խ��
                //if (colmun < 0) {
                //    colmun += 1;
                //}
                ////��ֱԽ��
                //else {
                //    row -= 1;
                //    colmun += 2;
                //}
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
    vector<int> res;
    res = Solution().findDiagonalOrder(matrix);
    for (auto it = res.begin(); it != res.end(); ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}