#include<iostream>
#include<sstream>
#include<string>
#include<stack>
using namespace std;
/*
给定一个字符串，逐个翻转字符串中的每个单词。
无空格字符构成一个 单词 。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
输入："the sky is blue"
输出："blue is sky the"
*/

class Solution {
public:
    string reverseWords(string s) {
        //利用stackFCLG特性，将单词插入
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
        //最后一个单词没有入栈，此时要额外加入
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
            //注意这里是不等于字符 ' ' 不是字符串
            if (s[start] != ' ') {
                //插入空格
                if (pos != 0) s[pos++] = ' ';
                int end = start;
                while (end < len && s[end] != ' ') s[pos++] = s[end++];
                //对单个单词进行翻转
                //reverse(s.begin()+pos-(end - start), s.end()+pos);//这里崩溃掉了
                //真是傻了，怎么能利用end呢，要从begin开始算下标
                //每一个单词 pos和end相比start前进相同步数
                reverse(s.begin() + pos - (end - start), s.begin() + pos);
                //s.begin() + pos 刚好是单词结束的下一位
                start = end;
            }
            else ++start;
        }
        //擦除多余的数据
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


