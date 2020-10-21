#include<iostream>
#include<string>
#include<functional>

using namespace std;


class Solution {
public:
    bool isUnique(string astr) {
        for (int i = 0; i < astr.size(); i++) {
            if (astr.find(astr[i]) != astr.rfind(astr[i])) {
                return false;
            }
        }
        return true;
    }
};


void test01() {
    string s = "leetcode";
    if (Solution().isUnique(s) == false)
        cout << "test01 passed" << endl;
    else
        cout << "test01 failed" << endl;
}

void test02() {
    string s = "abc";
    //Solution(s);
    if (Solution().isUnique(s) == true)
        cout << "test02 passed" << endl;
    else
        cout << "test02 failed" << endl;
}

int main() {

    test01();
    test02();
    system("pause");
    return 0;
}