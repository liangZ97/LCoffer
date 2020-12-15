#include<iostream>
#include<vector>
using namespace std;
/*
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
����: [0,1,0,3,12]
���: [1,3,12,0,0]
������ԭ�����ϲ��������ܿ�����������顣�������ٲ���������
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }
        for (; lastNonZeroFoundAt < nums.size(); ++lastNonZeroFoundAt) {
            nums[lastNonZeroFoundAt] = 0;
        }
    }
};
int main() {
    vector<int> nums{ 0,0,1 };
    Solution().moveZeroes(nums);
    for (auto x: nums) {
        cout << x << " ";
    }
    cout<<endl;
    return 0;
}