#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/*
���������������У���һ�����б�ʾջ��ѹ��˳��
���жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ�
���磬���� {1,2,3,4,5} ��ĳջ��ѹջ���У�
���� {4,5,3,2,1} �Ǹ�ѹջ���ж�Ӧ��һ���������У�
�� {4,3,5,1,2} �Ͳ������Ǹ�ѹջ���еĵ������С�
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> push_st;
        //stack<int> pop_st;
        //int count = 0;
        auto it = popped.begin();
        for (auto i : pushed) {
            push_st.push(i);
            while (!push_st.empty() && push_st.top() == *it
                && it != popped.end()) {
                push_st.pop();
                //++count;
                ++it;
            }
        }
        return push_st.empty();
    }
};