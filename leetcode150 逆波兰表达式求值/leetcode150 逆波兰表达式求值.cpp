#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
/*
根据 逆波兰表示法，求表达式的值。有效的运算符包括 +, -, *, / 。
每个运算对象可以是整数，也可以是另一个逆波兰表达式。
整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (!tokens.size())
            return 0;
        stack<int> st;
        for (int i = 0; i < tokens.size(); ++i) {
            //遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中。
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                if (tokens[i] == "+") {
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();
                    st.push(num2 + num1);
                }
                else if (tokens[i] == "-") {
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();
                    st.push(num2 - num1);
                }
                else if (tokens[i] == "*") {
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();
                    st.push(num2 * num1);
                }
                else if (tokens[i] == "/") {
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();
                    st.push(num2 / num1);
                }
            }
            else 
                st.push(stoi(tokens[i]));
            
        }
        int res=st.top();
        return res;
    }
};

int main() {
    string s1 = "2147482", s2 = "-214748";

    string s3 = "214748666666663", s4 = "-21474836488";

    cout << stoi(s1) << endl;

    cout << stoi(s2) << endl;
    //cout << stoi(s3) << endl;这里会出现异常，溢出
    cout << atoi(s3.c_str()) << endl;

    cout << atoi(s4.c_str()) << endl;
    return 0;
}