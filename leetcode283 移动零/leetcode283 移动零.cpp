#include<iostream>
#include<vector>
using namespace std;
/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
必须在原数组上操作，不能拷贝额外的数组。尽量减少操作次数。
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