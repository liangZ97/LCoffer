#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/*
输入两个整数序列，第一个序列表示栈的压入顺序，
请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如，序列 {1,2,3,4,5} 是某栈的压栈序列，
序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，
但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。
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