#include<iostream>
#include<string>
#include<sstream>
#include<stack>
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
