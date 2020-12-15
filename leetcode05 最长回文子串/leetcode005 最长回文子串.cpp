#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
*/
//动态规划
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        //const int len = s.size();
        int sublen = 1;
        int index = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        //初始化容器
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
                //此时的终止位置下标
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

//中心扩散法
//我们枚举所有的「回文中心」并尝试「扩展」，直到无法扩展为止
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
        //中心扩散法
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
