#include<iostream>
#include<stack>
using namespace std;
/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
调用 min、push 及 pop 的时间复杂度都是 O(1)。
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
