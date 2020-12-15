#include<iostream>
#include<vector>
using namespace std;
/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例:
输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
*/

//DP
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (!nums.size()) return 0;
        int res = nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

//贪心算法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            count += nums[i];
            res = max(res, count);
            if (count < 0)
                count = 0;
        }
        return res;
    }
};