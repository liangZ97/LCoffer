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

//字符串哈希，将字符串映射为一个ULL整数
typedef unsigned long long ULL;
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (!needle.size())
			return 0;
		vector<ULL> P(haystack.size() + 1);
		vector<ULL> S(haystack.size() + 1);
		P[0] = 1;
		S[0] = 0;
		int p = 131;//经验值
		//自然溢出法
		for (int i = 0; i < haystack.size(); ++i) {
			P[i + 1] = P[i] * p;
			S[i + 1] = S[i] * p + haystack[i];
		}
		ULL nee = 0;
		for (auto x : needle)
			nee = nee * p + x;
		for (int i = 0; i + needle.size() <= haystack.size(); ++i) {
			if (S[i + needle.size()] - S[i] * P[needle.size()] == nee)
				return i;
		}
		return -1;
	}
};

//BM算法
#define SIZE 128  //ASCII码共128个
class Solution1 {
	void generateBadChar(const string& needle, vector<int>& badChar) {
		for (int i = 0; i < needle.size(); ++i) {
			int ascii = (int)needle[i];
			badChar[ascii] = i;
		}
	}
	void generateGS(const string& needle, vector<int>& suffix, vector<bool>& prefix) {
		int m = needle.size();
		int len = 0;
		for (int i = 0; i < m - 1; ++i) {
			int j = i;
			len = 0;
			while (j >= 0 && needle[j] == needle[m - 1 - len]) {
				--j;
				++len;
				suffix[len] = j + 1;
			}
			if (j < 0)
				prefix[len] = true;
		}
	}
	int moveGS(int nPos, const vector<int>& suffix, const vector<bool>& prefix) {
		//找出来好后缀的长度
		int m = suffix.size();
		int len = m - 1 - nPos;
		//如果存在匹配后缀 
		if (suffix[len] != -1)
			return nPos + 1 - suffix[len];
		for(int i=nPos+2;i<m;++i){
			if (prefix[m - i])
				return i;
		}
		return m;
	}
public:
	int strStr(string haystack, string needle) {
		if (!needle.size())
			return 0;
		//字符哈希
		vector<int> badChar(SIZE, -1);
		generateBadChar(needle, badChar);
		int hPos = 0, nPos = 0;
		while (hPos + needle.size() <= haystack.size()) {
			nPos = needle.size() - 1;
			while (nPos >= 0 && needle[nPos] == haystack[hPos + nPos]) 
				--nPos;
			if (nPos < 0)
				return hPos;
			else {
				int movelen1 = nPos - badChar[(int)haystack[hPos + nPos]];
				//现在计算好后缀
				vector<int> suffix(needle.size(), -1);
				vector<bool> prefix(needle.size(), false);
				generateGS(needle, suffix, prefix);
				int movelen2 = 0;
				if (nPos < needle.size() - 1) {
					movelen2 = moveGS(nPos, suffix, prefix);
				}
				hPos = hPos + max(movelen1, movelen2);
			}
		}
		return -1;
	}
};

//KMP
class Solution2 {
	void getNext(vector<int>& next, const string& s) {
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
public:
	int strStr(string haystack, string needle) {
		if (!needle.size())
			return 0;
		vector<int> next(needle.size());
		//int* next = new int[needle.size()];
		getNext(next,needle );
		int j = 0;
		for (int i = 0; i < haystack.size(); ++i) {
			while (j > 0 && haystack[i] != needle[j])
				j = next[j - 1];
			if (haystack[i] == needle[j]) 
				++j;
			if (j == needle.size())
				return i - needle.size() + 1;
			
		}
		return -1;
	}
};

int main() {
	string s1 = "hello";
	string s2 = "ll";
	int pos = Solution2().strStr(s1, s2);
	cout << pos << endl;
	return 0;
}