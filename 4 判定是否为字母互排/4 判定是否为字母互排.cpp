#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        
        map<char, int> chars;
        for (int i = 0; i < s1.size(); i++)
            chars[s1[i]] ++;
        for (int i = 0; i < s2.size(); i++)
            chars[s2[i]] --;
        for (map<char, int>::iterator it = chars.begin(); it != chars.end(); it++) {
            if (it->second != 0) 
                return false;
        }
        return true;

        // sort(s1.begin(),s1.end());
        // sort(s2.begin(),s2.end());
        // return s1==s2;
        

    }
};

class Solution1 {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        vector<char> v1, v2;//需要保证v1和v2的大小符合要求
        v1.resize(s1.size());
        v2.resize(s2.size());
        for (int i = 0; i < s1.size(); i++) {
            v1[i] = s1[i];
            v2[i] = s2[i];
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for (int i = 0; i < s1.size(); i++) {
            cout << v1[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < s2.size(); i++) {
            cout << v2[i] << " ";
        }
        cout << endl;
        if (v1 == v2)
            return true;
        else
            return false;
       
    }
};
void test01() {
    string s1 = "abd";
    string s2 = "dab";

    if (Solution().CheckPermutation(s1,s2) == true)
        cout << "test02 passed" << endl;
    else
        cout << "test02 failed" << endl;
}


void test02() {
    string s1 = "abdcefghigk";
    string s2 = "dabcgsfsdfsdfsd";

    if (Solution().CheckPermutation(s1, s2) != true)
        cout << "test02 passed" << endl;
    else
        cout << "test02 failed" << endl;
}

void test03() {
    string s1 = "abdcefghigk";
    string s2 = "dabcgsfsdfsdfsd";

    if (Solution1().CheckPermutation(s1, s2) != true)
        cout << "test03 passed" << endl;
    else
        cout << "test03 failed" << endl;
}
void test04() {
    string s1 = "abdcefghigk";
    string s2 = "dabcgsfsdfsdfsd";

    if (Solution1().CheckPermutation(s1, s2) != true)
        cout << "test04 passed" << endl;
    else
        cout << "test04 failed" << endl;
}
int main()
{
    test01();
    test02();
    test03();
    test04();

    return 0;
}