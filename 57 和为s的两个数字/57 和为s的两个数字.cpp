#include <vector>
#include <iostream>
#include<unordered_set>
using namespace std;

/*
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
如果有多对数字的和等于s，则输出任意一对即可。
输入：nums = [2,7,11,15], target = 9
输出：[2,7] 或者 [7,2]
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> hash_result;
        for (int i : nums) {
            if (hash_result.count(target - i))
                return vector<int>{target - i, i};
            hash_result.insert(i);
        }
        return vector<int>{-1, -1};
    }
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     //vector<int> result;
    //     //双指针法
    //     int front=0,back=nums.size()-1;
    //     while(front<back){
    //         int sum=nums[front]+nums[back];
    //         if(sum==target) return vector<int>{nums[front],nums[back]};
    //         //利用有序特性
    //         else if(sum>target) back--;
    //         else front++;
    //     }
    //     return vector<int>{-1,-1};
    // }
};