#include<iostream>
#include<string>
using namespace std;
/*
�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
�붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ�
���磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"
����: s = "abcdefg", k = 2
���: "cdefgab"
*/
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string s1 = s.substr(0, n);//��0��ʼ��2���ַ�
        string s2 = s.substr(n);//���±�n��ʼֱ������ĩβ
        return s2 + s1;
    }
};