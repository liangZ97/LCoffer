#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        //利用deque容器特性可以很简单写出
        // deque<int> num;
        // for(int i:nums){
        //     if(i&1) num.push_front(i);
        //     else num.push_back(i);
        // }
        // for(int j=0;j<num.size();j++){
        //     nums[j]=num[j];
        // }
        // return nums;

        //下面利用头尾指针进行遍历，实现奇偶交换
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if ((nums[left] & 1) != 0) {
                left++;
                continue;
            }
            if ((nums[right] & 1) != 1) {
                right--;
                continue;
            }
            swap(nums[left++], nums[right--]);
        }
        return nums;
    }
};