#include<iostream>
#include<string>
using namespace std;
//��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��
//-------------------------------
//����ԭ�е��ַ���
class Solution {
public:
    string replaceSpace(string s) {
        for (int i = 0; i < s.size(); i++) {
            int pos;
            pos = s.find(" ");
            if (pos != -1)
                s.replace(pos, 1, "%20");
            else
                break;

        }
        return s;
    }
};
//����һ���µ��ַ���
class Solution1 {
public:
    string replaceSpace(string s) {
        string str = "";
        if (s.empty()) 
            return str;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ')
                str += "%20";
            else 
                str += s[i];
        }
        return str;
    }
};

int main() {
    string s = "We are happy.";
    string Replaes = "We%20are%20happy.";
    if (Replaes == Solution().replaceSpace(s))
        cout << "Solution01 passed " << Replaes << endl;
    else
        cout << "Solution01 failed" << endl;
    if (Replaes == Solution1().replaceSpace(s))
        cout << "Solution02 passed " << Replaes << endl;
    else
        cout << "Solution02 failed" << endl;
    return 0;
}