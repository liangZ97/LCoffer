#include<iostream>
#include<vector>
using namespace std;
/*
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。
现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
*/

//会超时
class Solution {
    int dfs(vector<int>& nums, int target, int left, int sum) {
        if (left == nums.size()) {
            if (sum == target)
                return 1;
            else
                return 0;
        }
        int numsCount = 0;
        //直接用target做判断可能溢出,可以用一个新int
        numsCount += dfs(nums, target, left + 1, sum - nums[left]);
        numsCount += dfs(nums, target, left + 1, sum + nums[left]);
        return numsCount;
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums, S, 0, 0);
    }
};

//S(P)−S(N)=T
//
//S(P) + S(N) + S(P) - S(N) = T + S(P) + S(N)
//S(P) + S(N) + S(P)−S(N) = T + S(P) + S(N)
//
//2S(P) = S(Q) + T
//2S(P) = S(Q) + T
//
//也就是：正数集的和的两倍 == 等于目标和 + 序列总和
//
//所以问题就转换成了，找到一个正数集P，其和的两倍等于目标和 + 序列总和。
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (auto &num : nums)sum += num;
        if (abs(S) > sum || (sum + S) % 2 != 0)
            return 0;
        //int可能会溢出
        long positiveSum = (sum + S) / 2;
        vector<int> res(positiveSum + 1);
        res[0] = 1;
        for (auto &num : nums) {
            for (int i = positiveSum; i >= num; --i) {
                res[i] += res[i - num];
            }
        }
        return res[positiveSum];
    }
};
