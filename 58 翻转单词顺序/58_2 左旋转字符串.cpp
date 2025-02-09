#include<iostream>
#include<string>
using namespace std;
/*
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
请定义一个函数实现字符串左旋转操作的功能。
比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"
输入: s = "abcdefg", k = 2
输出: "cdefgab"
*/
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string s1 = s.substr(0, n);//从0开始读2个字符
        string s2 = s.substr(n);//从下标n开始直到读到末尾
        return s2 + s1;
    }
};