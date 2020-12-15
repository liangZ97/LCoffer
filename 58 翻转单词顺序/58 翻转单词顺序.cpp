#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
using namespace std;
/*
����һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣
Ϊ������������ź���ͨ��ĸһ������
���������ַ���"I am a student. "�������"student. a am I"��
����: "the sky is blue"
���: "blue is sky the"
*/
class Solution {
public:
    string reverseWords(string s) {
        // //��ʵҲ���Բ���ջ���ԼӴ���Ϳ�
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
����һ���ַ���������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��
ʾ����
���룺"Let's take LeetCode contest"
�����"s'teL ekat edoCteeL tsetnoc"
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
        ////��ʱ�ҵ����ҵ�һ����Ϊ�ո�ĵط�
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