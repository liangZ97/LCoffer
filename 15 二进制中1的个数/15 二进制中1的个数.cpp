#include<iostream>

using namespace std;
/*
请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。
例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        unsigned int CountBinaryOne = 0;
        //int i=0;
        //int flag=1;
        while (n != 0) {
            if (n & 1) CountBinaryOne++;
            n >>= 1;
        }
        return (int)CountBinaryOne;
    }
};

int main() {
    uint32_t n = 11;
    int count;
    count = Solution().hammingWeight(n);
    cout << count << endl;
    n = 0b11111111111111111111111111111101;
    count = Solution().hammingWeight(n);
    cout << count << endl;
    return 0;
}