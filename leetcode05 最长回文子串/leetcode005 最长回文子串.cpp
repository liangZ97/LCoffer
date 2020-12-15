#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ 1000��
����: "babad"
���: "bab"
ע��: "aba" Ҳ��һ����Ч�𰸡�
*/
//��̬�滮
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        //const int len = s.size();
        int sublen = 1;
        int index = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        //��ʼ������
        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = 1;
            if (i < s.size() - 1 && s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                sublen = 2;
                index = i;
            }
        }
        for (int l=3; l <= s.size(); ++l) {
            for (int i = 0; i + l - 1 < s.size(); ++i) {
                //��ʱ����ֹλ���±�
                int j = i + l - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                    index = i;
                    sublen = l;
                }
            }
        }
        return s.substr(index, sublen);
    }
};

//������ɢ��
//����ö�����еġ��������ġ������ԡ���չ����ֱ���޷���չΪֹ
class Solution1 {
    string CenterSpread(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        //left+=1 right-=1 len=right-left+1
        return s.substr(left + 1, right - left + 1);
    }
public:
    string longestPalindrome(string s) {
        //������ɢ��
        if (s.size() < 2) return s;
        string res = s.substr(0, 1);
        int sublen = 1;
        for (int i = 0; i < s.size() - 1; ++i) {
            string OddString = CenterSpread(s, i, i);
            string EvenString = CenterSpread(s, i, i + 1);
            if ((OddString.size() > sublen) || (EvenString.size() > sublen)) {
                res = OddString.size() > EvenString.size() ? OddString : EvenString;
                sublen = OddString.size() > EvenString.size() ? OddString.size() : EvenString.size();
            }
            else continue;
        }
        return res;
    }
};

int main() {
    string s = "babad";
    string res;
    res = Solution1().longestPalindrome(s);
    cout << res << endl;
    return 0;
}
