#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
给定一个 haystack 字符串和一个 needle 字符串，
在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
如果不存在，则返回  -1。
当 needle 是空字符串时，我们应当返回0
输入: haystack = "hello", needle = "ll"
输出:2
*/

class Solution {
public:
    void get_bmB(string& T, vector<int>& bmB)//坏字符
    {
        int tlen = T.size();
        for (int i = 0; i < 256; i++)//不匹配直接移动子串
        {
            bmB.push_back(tlen);
        }
        for (int i = 0; i < tlen - 1; i++)//靠右原则
        {
            bmB[T[i]] = tlen - i - 1;
        }
    }

    void get_suff(string& T, vector<int>& suff)
    {
        int tlen = T.size();
        int k;
        for (int i = tlen - 2; i >= 0; i--)
        {
            k = i;
            while (k >= 0 && T[k] == T[tlen - 1 - i + k])
                k--;
            suff[i] = i - k;
        }
    }

    void get_bmG(string& T, vector<int>& bmG)//好后缀
    {
        int i, j;
        int tlen = T.size();
        vector<int> suff(tlen + 1, 0);
        get_suff(T, suff);//suff存储子串的最长匹配长度
        //初始化 当没有好后缀也没有公共前缀时
        for (i = 0; i < tlen; i++)
            bmG[i] = tlen;
        //没有好后缀 有公共前缀 调用suff 但是要右移一位 类似KMP里的next数组
        for (i = tlen - 1; i >= 0; i--)
            if (suff[i] == i + 1)
                for (j = 0; j < tlen - 1; j++)
                    if (bmG[j] == tlen)//保证每个位置不会重复修改
                        bmG[j] = tlen - 1 - i;
        //有好后缀 有公共前缀
        for (i = 0; i < tlen - 1; i++)
            bmG[tlen - 1 - suff[i]] = tlen - 1 - i;//移动距离
    }

    int strStr(string haystack, string needle) {

        int i = 0;
        int j = 0;
        int tlen = needle.size();
        int slen = haystack.size();

        vector<int> bmG(tlen, 0);
        vector<int> bmB;
        get_bmB(needle, bmB);
        get_bmG(needle, bmG);

        while (i <= slen - tlen)
        {
            for (j = tlen - 1; j > -1 && haystack[i + j] == needle[j]; j--);
            if (j == (-1))
                return i;
            i += max(bmG[j], bmB[haystack[i + j]] - (tlen - 1 - j));
        }
        return -1;
    }
};

//字符串哈希
typedef unsigned long long ULL;
class Solution1 {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int p = 131;
        vector<ULL> P(haystack.size() + 1);
        vector<ULL> S(haystack.size() + 1);
        P[0] = 1;
        S[0] = 0;
        for (int i = 0; i < haystack.size(); i++) {
            P[i + 1] = P[i] * p;
            S[i + 1] = S[i] * p + haystack[i];
        }
        ULL nee = 0;
        //计算字串的哈希值
        for (auto x : needle) nee = nee * p + x;
        // for (int i = 1; i + needle.size() - 1 <= haystack.size(); i++) {
        //     if (S[i + needle.size() - 1] - S[i - 1] * P[needle.size()] == nee) return i - 1;
        // }
        for (int i = 0; i + needle.size() <= haystack.size(); i++) {
            if (S[i + needle.size()] - S[i] * P[needle.size()] == nee) return i;
        }
        return -1;
    }
};


//BM算法
#define SIZE 128
class Solution2 {
    void generateBadChar(const string& m, vector<int>& badchar) {
        for (int i = 0; i < m.size(); ++i) {
            int ascii = (int)m[i];
            //每个字符最后一次出现的下标
            badchar[ascii] = i;
        }
    }
    void generateGS(const string& m, vector<int>& suffix, vector<bool>& prefix) {
        int s = m.size();
        int k = 0;//公共后缀长度
        for (int i = 0; i < s - 1; ++i) {
            int j = i;
            k = 0;
            //前缀中和后缀公共子串
            while (j >=0 && m[j] == m[s - 1 - k]) {
                --j;
                ++k;
                suffix[k] = j + 1;
            }
            if (j == -1)
                prefix[k] = true;
        }
    }
    int moveByGS(int j, vector<int>& suffix, vector<bool>& prefix) {
        int m = suffix.size();
        //好后缀的长度
        int k = m - 1 - j;
        if(suffix[k]!=-1){
            return j + 1 - suffix[k];
        }
        else {
            for (int i = j + 2; i < m; ++i) {
                if (prefix[m - i])
                    return i;
            }
            return m;
        }
    }
public:
    int strStr(string haystack, string needle) {
        //先排除意外情况
        if (!needle.size()) return 0;
        vector<int> badchar(SIZE, -1);
        generateBadChar(needle, badchar);
        //找到坏字符下标
        int hPos = 0, nPos;
        while (hPos + needle.size() <= haystack.size()) {
            //模式串从后往前匹配
            nPos = needle.size() - 1;
            for (nPos; nPos >= 0; --nPos) {
                if (haystack[hPos + nPos] != needle[nPos])
                    break;
            }
            if (nPos < 0)
                return hPos;
            //此时 hPos + nPos 就是坏字符所在下标
            //主串是随着模式串后移的
            int moveLen1 = nPos - badchar[haystack[hPos + nPos]];
            //const int m = needle.size();
            //int suffix[m];
            vector<int> suffix(needle.size(), -1);
            vector<bool> prefix(needle.size(), false);
            generateGS(needle, suffix, prefix);
            //保证存在好后缀
            int moveLen2 = 0;
            if (nPos < needle.size() - 1) {
                moveLen2 = moveByGS(nPos, suffix, prefix);
            }
            hPos = hPos + max(moveLen1, moveLen2);
        }
        return -1;
    }
};

//KMP
class Solution3 {
public:
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int *next=new int[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                delete[] next;
                return (i - needle.size() + 1);
            }
        }
        delete[] next;
        return -1;
    }
};
