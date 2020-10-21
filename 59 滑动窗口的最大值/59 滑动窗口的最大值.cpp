#include<iostream>
#include<vector>
#include<deque>
using namespace std;
/*
����һ������ nums �ͻ������ڵĴ�С k�����ҳ����л�������������ֵ��
����: nums = [1,3,-1,-3,5,3,6,7], �� k = 3
���: [3,3,5,5,6,7]
*/
class Solution {
public:
    //��һ�֣����汩��
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
    //�ڶ��֣�ά��˫�˶��У�ά����ͷ�Ƿ��Ѿ�������
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> deq;//����������index�����������ֵ
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            //while�ⲽ������Ϊ���õ�ǰ�������ֵ������ֵ�ŵ�tem�Ķ�ͷ
            while (!deq.empty() && nums[i] > nums[deq.back()]) {
                deq.pop_back();
            }
            //�����if�ж������еĵڶ�����Ϊ���ж϶�ͷ�Ƿ����
            //Ҳ����˵��ͷ�������Ƿ�С�ڵ�ǰ����
            if (!deq.empty() && deq.front() < i - k + 1) deq.pop_front();
            deq.push_back(i);
            //��֤�ӿ�ʼ�ı߽�ŷ���
            if (i >= k - 1) ans.push_back(nums[deq.front()]);
        }
        return ans;

    }
};
//�Լ�д��
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //if(!nums.size()) return vector<int>();
        vector<int> res;
        //����������index�����������ֵ����ΪҪ���±��жϻ������ڴ�С��
        deque<int> deq;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            //�ֳ��Ĳ���1.�жϵ�ǰ�����Ƿ����Ҫ��
            if (!deq.empty() && deq.front() < i - k + 1) deq.pop_front();
            //2.����жϣ������β����С�ڵ�ǰԪ�ص�ֵ
            while (!deq.empty() && nums[deq.back()] < nums[i]) deq.pop_back();
            //3.����ǰ�������������
            deq.push_back(i);
            //4.���㴰��Ҫ��ķ���������
            if (i >= k - 1) res.push_back(nums[deq.front()]);
        }
        return res;
    }
};