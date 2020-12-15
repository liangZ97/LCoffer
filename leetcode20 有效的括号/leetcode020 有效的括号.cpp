#include<iostream>
#include<stack>
#include<string>
using namespace std;
/*
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
��Ч�ַ��������㣺
�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ע����ַ����ɱ���Ϊ����Ч�ַ�����
*/
class Solution {
public:
    bool isValid(string s) {
        if (!s.size())
            return true;
        stack<char> st;
        for (char ch : s) {                  
            if (ch == '(' || ch == '[' || ch == '{')
                switch (ch) {
                case '(':
                    st.push(')');
                    break;
                case '[':
                    st.push(']');
                    break;
                case '{':
                    st.push('}');
                    break;
                default:
                    break;
                }
            else {
                if (st.size() && st.top() == ch)
                    st.pop();
                else
                    return false;
                
            }
        }
            return st.empty();
    }
};

class Solution1 {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            // ��������� �Ǳ����ַ���ƥ��Ĺ����У�ջ�Ѿ�Ϊ���ˣ�û��ƥ����ַ��ˣ�˵��������û���ҵ���Ӧ�������� return false
            // �ڶ������ �����ַ���ƥ��Ĺ����У�����ջ��û������Ҫƥ����ַ�������return false
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop(); // st.top() == s[i]
        }
        // ��һ����� ��ʱ�����Ѿ����������ַ���������ջ��Ϊ�գ�˵������Ӧ��������û����������ƥ�䣬����return false�������return true
        return st.empty();
    }
};

int main() {
    string s = "]";
    bool flag = Solution().isValid(s);
    int judge=flag == true;
    cout << judge << endl;
    return 0;
}