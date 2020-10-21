#include<iostream>
#include<vector>
#include<deque>
using namespace std;
/*
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7]
*/
class Solution {
public:
    //第一种，常规暴力
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0, right = k - 1;
        vector<int> res;
        //int max=0;
        while (right < nums.size()) {
            int tempmax = nums[left];
            for (int i = left; i <= right; ++i) {
                tempmax = (tempmax > nums[i]) ? tempmax : nums[i];
            }
            res.emplace_back(tempmax);
            ++left;
            ++right;
        }
        return res;
    }
};
class Solution1 {
public:
    //第二种，维护双端队列，维护队头是否已经出区间
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> deq;//存的是数组的index，不是数组的值
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            //while这步操作是为了让当前窗口最大值的索引值放到tem的队头
            while (!deq.empty() && nums[i] > nums[deq.back()]) {
                deq.pop_back();
            }
            //这里的if判断条件中的第二个是为了判断队头是否过期
            //也就是说队头的索引是否小于当前索引
            if (!deq.empty() && deq.front() < i - k + 1) deq.pop_front();
            deq.push_back(i);
            //保证从开始的边界才返回
            if (i >= k - 1) ans.push_back(nums[deq.front()]);
        }
        return ans;

    }
};
//自己写的
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //if(!nums.size()) return vector<int>();
        vector<int> res;
        //存的是数组的index，不是数组的值，因为要用下标判断滑动窗口大小。
        deque<int> deq;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            //分成四步。1.判断当前窗口是否符合要求
            if (!deq.empty() && deq.front() < i - k + 1) deq.pop_front();
            //2.入队判断，清除队尾所有小于当前元素的值
            while (!deq.empty() && nums[deq.back()] < nums[i]) deq.pop_back();
            //3.将当前索引放入队列中
            deq.push_back(i);
            //4.满足窗口要求的放入数组中
            if (i >= k - 1) res.push_back(nums[deq.front()]);
        }
        return res;
    }
};