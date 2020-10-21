#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
���˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�
2��10Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13������С��Ϊ 0 �����Կ����������֡�A ������Ϊ 14
����: [1,2,3,4,5]
���: True
*/
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //���ҳ�0�ĸ���
        int i = 0;
        while (i < nums.size() && nums[i] == 0) ++i;
        if (i == nums.size()) return true;
        for (int j = i; j < nums.size() - 1; ++j) {
            if (nums[j] == nums[j + 1]) return false;
        }
        return nums[nums.size() - 1] - nums[i] <= 4;
    }
};