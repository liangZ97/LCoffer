#include<iostream>
#include<vector>
#include<set>

using namespace std;

/*
��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�
������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ�
���ҳ�����������һ���ظ������֡�
*/

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        set<int> nSet;
        for (int i : nums)
        {
            if (nSet.count(i))
                return i;
            else
                nSet.insert(i);
        }
        return -1;
    }
};