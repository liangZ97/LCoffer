#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14
输入: [1,2,3,4,5]
输出: True
*/
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //先找出0的个数
        int i = 0;
        while (i < nums.size() && nums[i] == 0) ++i;
        if (i == nums.size()) return true;
        for (int j = i; j < nums.size() - 1; ++j) {
            if (nums[j] == nums[j + 1]) return false;
        }
        return nums[nums.size() - 1] - nums[i] <= 4;
    }
};