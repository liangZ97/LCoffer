#include<iostream>
#include<vector>
using namespace std;
/*
����һ���������飬ʵ��һ�����������������������ֵ�˳��
ʹ����������λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�
*/
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        //����deque�������Կ��Ժܼ�д��
        // deque<int> num;
        // for(int i:nums){
        //     if(i&1) num.push_front(i);
        //     else num.push_back(i);
        // }
        // for(int j=0;j<num.size();j++){
        //     nums[j]=num[j];
        // }
        // return nums;

        //��������ͷβָ����б�����ʵ����ż����
        int front = 0;
        int back = nums.size() - 1;
        while (front < back) {
            //ͷ��ָ��������������ߣ�ֱ���ҵ�ż��
            if ((nums[front] & 1)) {
                front++;
                continue;
            }
            //β��ָ����ż������ǰ�ߣ�ֱ���ҵ�����
            if (!(nums[back] & 1)) {
                back--;
                continue;
            }
            //��ʱͷ��Ϊż����β��Ϊ����
            swap(nums[front++], nums[back--]);
            //β��ָ��ͣ���������������
        }
        return nums;
    }
};