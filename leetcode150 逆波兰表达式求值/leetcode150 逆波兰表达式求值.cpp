#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
/*
���� �沨����ʾ��������ʽ��ֵ����Ч����������� +, -, *, / ��
ÿ��������������������Ҳ��������һ���沨�����ʽ��
��������ֻ�����������֡�
�����沨�����ʽ������Ч�ġ����仰˵�����ʽ�ܻ�ó���Ч��ֵ�Ҳ����ڳ���Ϊ 0 �������
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (!tokens.size())
            return 0;
        stack<int> st;
        for (int i = 0; i < tokens.size(); ++i) {
            //������������ջ�����������ȡ��ջ���������ֽ��м��㣬�������ѹ��ջ�С�
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
    //cout << stoi(s3) << endl;���������쳣�����
    cout << atoi(s3.c_str()) << endl;

    cout << atoi(s4.c_str()) << endl;
    return 0;
}