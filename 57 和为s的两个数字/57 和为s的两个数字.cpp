#include <vector>
#include <iostream>
#include<unordered_set>
using namespace std;

/*
����һ����������������һ������s���������в�����������ʹ�����ǵĺ�������s��
����ж�����ֵĺ͵���s�����������һ�Լ��ɡ�
���룺nums = [2,7,11,15], target = 9
�����[2,7] ���� [7,2]
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
    //     //˫ָ�뷨
    //     int front=0,back=nums.size()-1;
    //     while(front<back){
    //         int sum=nums[front]+nums[back];
    //         if(sum==target) return vector<int>{nums[front],nums[back]};
    //         //������������
    //         else if(sum>target) back--;
    //         else front++;
    //     }
    //     return vector<int>{-1,-1};
    // }
};