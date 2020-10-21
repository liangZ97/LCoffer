#include<iostream>
#include<ctime>
using namespace std;
/*
* 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法
*/
class Solution {
public:
    int numWays(int n) {
        //因为青蛙一次只能蹦两阶台阶，所以上第n阶台阶只有n-1和n-2种方法，其实也就是求斐波那契数列
        if (n == 0 || n == 1)
            return 1;
        else {
            int a[2] = { 1,1 };//注意这里不是从{0，1}开始遍历的，因为这个下标等于去掉0的斐波那契数列数列下标
            for (int i = 2; i <= n; i++)
                a[i & 1] = (a[0] + a[1]) % (int)(1e9 + 7);
            return a[n & 1];
        }
    }
};

int main() {
    srand((unsigned int)time(NULL));
    int n = rand() % 101;
    cout << "n= " << n << endl;
    int numWays = Solution().numWays(n);
    cout << "numWays= " << numWays << endl;
    
    return 0;
}