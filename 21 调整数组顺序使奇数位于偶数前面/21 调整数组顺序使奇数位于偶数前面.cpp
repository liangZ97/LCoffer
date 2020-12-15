#include<iostream>
#include<vector>
using namespace std;
/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
*/
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
        int front = 0;
        int back = nums.size() - 1;
        while (front < back) {
            //头部指针是奇数，向后走，直到找到偶数
            if ((nums[front] & 1)) {
                front++;
                continue;
            }
            //尾部指针是偶数，向前走，直到找到奇数
            if (!(nums[back] & 1)) {
                back--;
                continue;
            }
            //此时头部为偶数，尾部为奇数
            swap(nums[front++], nums[back--]);
            //尾部指针停留在最后面奇数处
        }
        return nums;
    }
};