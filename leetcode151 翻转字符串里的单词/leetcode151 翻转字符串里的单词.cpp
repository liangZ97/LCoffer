#include<iostream>
#include<sstream>
#include<string>
#include<stack>
using namespace std;
/*
����һ���ַ����������ת�ַ����е�ÿ�����ʡ�
�޿ո��ַ�����һ�� ���� ��
�����ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����
����������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����
���룺"the sky is blue"
�����"blue is sky the"
*/

class Solution {
public:
    string reverseWords(string s) {
        //����stackFCLG���ԣ������ʲ���
        if (!s.size()) return s;
        stack<string> st;
        int left = 0, right = s.size() - 1;
        while (left <= right && s[left] == ' ') ++left;
        while (left <= right && s[right] == ' ') --right;
        string word;
        while (left <= right) {
            if (word.size() && s[left] == ' ') {
                st.push(word);
                word = "";
            }
            if (s[left] != ' ') word += s[left];
            ++left;
        }
        //���һ������û����ջ����ʱҪ�������
        st.push(word);
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
            if (!st.empty()) res += ' ';
        }
        return res;
    }
};

class Solution1 {
public:
    string reverseWords(string s) {
        if (!s.size()) return s;
        reverse(s.begin(), s.end());
        int len = s.size();
        int pos = 0;
        for (int start = 0; start < len; ) {
            //ע�������ǲ������ַ� ' ' �����ַ���
            if (s[start] != ' ') {
                //����ո�
                if (pos != 0) s[pos++] = ' ';
                int end = start;
                while (end < len && s[end] != ' ') s[pos++] = s[end++];
                //�Ե������ʽ��з�ת
                //reverse(s.begin()+pos-(end - start), s.end()+pos);//�����������
                //����ɵ�ˣ���ô������end�أ�Ҫ��begin��ʼ���±�
                //ÿһ������ pos��end���startǰ����ͬ����
                reverse(s.begin() + pos - (end - start), s.begin() + pos);
                //s.begin() + pos �պ��ǵ��ʽ�������һλ
                start = end;
            }
            else ++start;
        }
        //�������������
        s.erase(s.begin() + pos, s.end());
        return s;
        //return s.substr(0,pos);
    }
};
int main() {
    string s = "  Leetcode is  fun ";
    string res = Solution1().reverseWords(s);
    cout << s << endl;
    cout << res << endl;
    return 0;
}

class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string res, str;
        while (ss >> str)
            res = str + ' ' + res;
        //while (ss >> str) res.insert(0, str + " ");
        return res.substr(0, res.size() - 1);
    }
};


