#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> v;
        for (int i = 0; i < pow(10,n); i++) v.push_back(i);
        return v;
    }
};

int main() {
    int n = 1;
    //int n = 2;
    vector<int> v=Solution().printNumbers(n);
    for (int j : v)
        cout << j << " ";
    cout << endl;
    return 0;
}

