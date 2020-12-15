#include<iostream>
#include<stack>
using namespace std;
/*
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص� min �����ڸ�ջ�У�
���� min��push �� pop ��ʱ�临�Ӷȶ��� O(1)��
*/
class MinStack {
    stack<int> st;
    stack<int> min_st;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    void push(int x) {
        st.push(x);
        if (min_st.empty() || x <= min_st.top())
            min_st.push(x);
        else
            min_st.push(min_st.top());
    }

    void pop() {
        if (!st.empty()) {
            //if (st.top() == min_st.top()) 
            min_st.pop();
            st.pop();
        }
    }
    int top() {
        return st.top();
    }
    int min() {
        return min_st.top();
    }
};
