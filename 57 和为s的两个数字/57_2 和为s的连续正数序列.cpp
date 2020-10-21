#include <iostream>
#include <vector>
#include<ctime>
using namespace std;
/*
����һ�������� target ��������к�Ϊ target ���������������У����ٺ�������������
�����ڵ�������С�������У���ͬ���а����׸����ִ�С�������С�
���룺target = 15
�����[[1,2,3,4,5],[4,5,6],[7,8]]
*/
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> result;
        //����һ���������ڣ�����ҿ� [ )���ҳ�������С���ĵĶ���ʽ
        int i = 1;//�������ڵ���߽�
        int j = 1;//�������ڵ���߽�
        int sum = 0;
        while (i <= target / 2) {//��i>targetʱ���������ڲ���������sum==target
            if (sum < target) {
                sum += j;
                ++j;
            }
            else if (sum > target) {
                sum -= i;
                ++i;
            }
            else {
                vector<int> vec;
                vec.clear();
                for (int a = i; a < j; a++) vec.emplace_back(a);
                result.emplace_back(vec);
                //���������ƶ���Ѱ�Һ��ʵ�����
                sum -= i;
                ++i;
            }
        }
        return result;
    }
};

int main() {
    srand((unsigned int)time(NULL));
    int target=rand()%10+5;
    //int target = 11;
    cout <<target <<endl;
    //ע�⣡�����������������������������
    //����������ܲ��û����������
    vector<vector<int>> result = Solution().findContinuousSequence(target);
    //int rows = result.size();
    for (int rows = 0; rows < result.size(); ++rows) {
        for (int cloumns = 0; cloumns < result[rows].size(); ++cloumns)
            cout << result[rows][cloumns] << " ";
        cout << endl;
    }
    return 0;
}