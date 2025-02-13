﻿#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
输入：s = "3[a]2[bc]"
输出："aaabcbc"
*/

class Solution {
public:
    string analysis(const string& s, int& index) {
        string res;
        int num = 0;
        while (index < s.size()) {
            if (s[index] >= '0' && s[index] <= '9')
                num = num * 10 + (s[index] - '0');
            else if (s[index] == '[') {
                string temp = analysis(s, ++index);
                while (num > 0) {
                    res += temp;
                    --num;
                }
            }
            else if (s[index] == ']')
                break;
            else
                res += s[index];
            ++index;
        }
        return res;
    }
    string decodeString(string s) {
        int index = 0;
        return analysis(s, index);
    }
};

int main() {
    string s = "3[a]2[bc]";
    string res = Solution().decodeString(s);
    cout << s << endl;
    cout << res << endl;
    return 0;
}


class Solution {
public:
    string getDigits(string& s, size_t& ptr) {
        string ret = "";
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    string getString(vector <string>& v) {
        string ret;
        for (const auto& s : v) {
            ret += s;
        }
        return ret;
    }

    string decodeString(string s) {
        vector <string> stk;
        size_t ptr = 0;

        while (ptr < s.size()) {
            char cur = s[ptr];
            if (isdigit(cur)) {
                // 获取一个数字并进栈
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            }
            else if (isalpha(cur) || cur == '[') {
                // 获取一个字母并进栈
                stk.push_back(string(1, s[ptr++]));
            }
            else {
                ++ptr;
                vector <string> sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                // 左括号出栈
                stk.pop_back();
                // 此时栈顶为当前 sub 对应的字符串应该出现的次数
                int repTime = stoi(stk.back());
                stk.pop_back();
                string t, o = getString(sub);
                // 构造字符串
                while (repTime--) t += o;
                // 将构造好的字符串入栈
                stk.push_back(t);
            }
        }

        return getString(stk);
    }
};
