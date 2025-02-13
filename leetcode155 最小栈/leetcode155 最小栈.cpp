﻿#include<iostream>
#include<stack>
using namespace std;
/*
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。
输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
输出：
[null,null,null,null,-3,null,0,-2]
*/
class MinStack {
    //定义一个栈和一个辅助栈
    stack<int> st;
    stack<int> minSt;
public:
    /** initialize your data structure here. */
    MinStack() {}
    void push(int x) {
        st.push(x);
        //保证st和minSt有相同多的元素，不会出去最小元素后丢失第二小元素
        if (minSt.empty() || x <= minSt.top())
            minSt.push(x);
        else
            minSt.push(minSt.top());
    }
    void pop() {
        st.pop();
        minSt.pop();
    }
    int top() {
        return st.top();
    }
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */