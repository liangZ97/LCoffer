#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/*
请根据每日 气温 列表，重新生成一个列表。
对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。
如果气温在这之后都不会升高，请在该位置用 0 来代替。
例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (!T.size())
            return {};
        vector<int> res(T.size(), 0);
        stack<pair<int, int>> st;
        //size_t size = T.size();
        for (int i = 0; i < T.size();++i) {
            while (!st.empty() && T[i] > st.top().second) {
                res[st.top().first] = i - st.top().first;
                st.pop();
            }
            st.push({ i,T[i] });
        }
        return res;
    }
};

//同样的，因为数组可以看作是哈希表，我们只需要用栈保存下标也能达到O(1)复杂度
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (!T.size())
            return {};
        vector<int> res(T.size(), 0);
        stack<int> st;
        for (int i = 0; i < T.size(); ++i) {
            while (!st.empty()&&T[i]>T[st.top()]) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

//最好的是采用伪动态规划，从后往前遍历，可以省去栈的开销
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (!T.size())
            return {};
        vector<int> res(T.size(), 0);
        for (int i = T.size() - 1; i >= 0; --i) {
            int j = i + 1;
            while (j < T.size()) {
                if (T[j] > T[i])
                    res[i] = j - i;
                else if (res[j] == 0)
                    break;
                else
                    //跳转到比这个数值大的后面一个数值
                    j += res[j];
            }
        }
        return res;
    }
};