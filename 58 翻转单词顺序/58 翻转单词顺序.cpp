#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
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

/*
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
示例：
输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"
*/
class Solution {
public:
    string reverseWords(string s) {
        if (!s.size()) return s;
        string str, res;
        istringstream is(s);
        while (is >> str) {
            reverse(str.begin(), str.end());
            res += str + " ";
        }
        return res.substr(0, res.size() - 1);
        //if (!s.size()) return s;
        //int left = 0, right = s.size() - 1;
        //while (left <= right && s[left] == ' ') ++left;
        //while (left <= right && s[right] == ' ') --right;
        ////此时找到左右第一个不为空格的地方
        //queue<string> qu;
        //string word;
        //while (left <= right) {
        //    if (s[left] != ' ') word += s[left];
        //    if (word.size() && s[left] == ' ') {
        //        reverse(word.begin(), word.end());
        //        qu.push(word);
        //        word.clear();
        //    }
        //    ++left;
        //}
        //reverse(word.begin(), word.end());
        //qu.push(word);
        //string res;
        //while (!qu.empty()) {
        //    res += qu.front();
        //    qu.pop();
        //    if (!qu.empty()) res += ' ';
        //}
        //return res;

    }
};