#include<iostream>
#include<ctime>
using namespace std;
/*
 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
 每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
 例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
*/
class Solution {
public:
    int cuttingRope(int n) {
        //任何大于1的数都可由2和3相加组成
        //m>1 最少要分成两段
        if (n < 2) return -1;
        else if (n == 2) return 1;
        else if (n == 3) return 2;
        else {//2*2>1*3  2*3>2*2*1 3*3>2*2*2
             //大于4，分解为3优于分解为2
            int sum = 1;
            while (n > 4) {
                sum *= 3;
                n -= 3;
            }
            //5 6 7 
            return n * sum;
        }
    }
};

/*
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为 k[0],k[1]...k[m - 1] 。请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
2 <= n <= 1000
*/

class Solution1 {
public:
    int cuttingRope(int n) {
        //任何大于1的数都可由2和3相加组成
        //m>1 最少要分成两段
        if (n < 2) return -1;
        else if (n == 2) return 1;
        else if (n == 3) return 2;
        else {//2*2>1*3  2*3>2*2*1 3*3>2*2*2
             //大于4，分解为3优于分解为2
            unsigned sum = 1;
            while (n > 4) {
                sum = (sum * 3) % (int)(1e9 + 7);
                //sum=sum%(int)(1e9+7);
                n -= 3;
            }
            //5 6 7 
            return (unsigned int)(n * sum) % (int)(1e9 + 7);
        }
    }
};



int main() {
    srand((unsigned int)time(NULL));
    int k=rand()%5+100;
    cout << "k is " << k << endl;
    //int ReturnMulitiSum = Solution().cuttingRope(k);
    int ReturnMulitiSum = Solution1().cuttingRope(k);
    cout << "ReturnMulitiSum is " << ReturnMulitiSum << endl;
    return 0;
}