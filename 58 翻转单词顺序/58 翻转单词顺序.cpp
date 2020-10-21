#include<iostream>
#include<string>
#include<sstream>
#include<stack>
using namespace std;
/*
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
为简单起见，标点符号和普通字母一样处理。
例如输入字符串"I am a student. "，则输出"student. a am I"。
输入: "the sky is blue"
输出: "blue is sky the"
*/
class Solution {
public:
    string reverseWords(string s) {
        // //其实也可以不用栈，稍加处理就可
        // string res,str;
        // istringstream is(s);
        // while(is>>str){
        //     res=str+" "+res;
        // }
        // return res.substr(0,res.size()-1);
        stack<string> stk;
        string res, str;
        istringstream ss(s);
        while (ss >> str) {
            stk.push(str);
            stk.push(" ");
        }
        if (!stk.empty())
            stk.pop();
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
