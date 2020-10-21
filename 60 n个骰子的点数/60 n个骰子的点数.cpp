#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。
输入n，打印出s的所有可能的值出现的概率。
你需要用一个浮点数数组返回答案，
其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。
输入: 2
输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
*/
class Solution {
public:
    vector<double> twoSum(int n) {
        //定义一个数组保存所有状态，一维是第n次时，二维为第n次时所有可能情况
        int dp[12][70] = { 0 };
        //dp[i][j]，表示投掷完i枚骰子后，点数j的出现次数
        //我们只能知道第一次的情况，也是边界条件
        for (int i = 1; i <= 6; i++)
        {
            //为了看起来更直白，第一层浪费了
            dp[1][i] = 1;
        }
        //开始计算骰子点数出现的次数
        //第i个骰子
        for (int i = 2; i <= n; ++i) {
            //i个骰子可能出现的点数
            for (int j = i; j <= n * 6; j++) {
                //计算出现的次数
                for (int k = 1; k <= 6; k++) {
                    if (j - k < i - 1) break;
                    //第i层j点出现的次数只可能是i-1层，j-(1-6)出现的次数和
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        vector<double> res;
        int SumCount = pow(6, n);
        //只需要输出最后一层
        for (int i = n; i <= n * 6; i++) {
            res.emplace_back((double)dp[n][i] * 1.0 / SumCount);
        }
        return res;
    }
};

//在上面的方法中，我们只输出了最后一层，
//所以如果能将二维数组转化为一维数组一定会节约很多的空间开销
class Solution1 {
public:
    vector<double> twoSum(int n) {
        //如果用一维数组，那么写数据必须要逆序来写
        int dp[70] = { 0 };
        //设置初始值，第一次1-6出现的次数均为一次
        //为了看起来方便，利用下标表示骰子和值
        for (int i = 1; i <= 6; ++i) {
            dp[i] = 1;
        }
        //下面还应该是三重循环
        for (int count = 2; count <= n; ++count) {
            //对于每次新增一个骰子，按可能的大小逆序写下来
            for (int i = count * 6; i >= count; --i) {//for循环里面写可能出现的点数，外面再动态规划遍历
                dp[i] = 0;//注意这里要进行清零
                //如果从大到下遍历，会出错，将break改为continue则对 
                // for (int cur = 1; cur <= 6; ++cur)
                // {
                //     //此时进行动态规划
                //     if (i - cur < count - 1) break;//保证骰子值至少为骰子数
                //     //注意这里dp[i]原本有可能不为空的
                //     dp[i] += dp[i - cur];
                // }
                for (int cur = 6; cur >= 1; --cur)
                {
                    //此时进行动态规划
                    //保证骰子值至少为骰子数
                    if (i - cur < count - 1) continue;
                    //注意这里dp[i]原本有可能不为空的，所以之前要清空
                    dp[i] += dp[i - cur];
                }
            }
        }
        vector<double> res;
        int SumCount = pow(6, n);
        for (int i = n; i <= n * 6; ++i) {
            res.emplace_back((double)dp[i] * 1.0 / SumCount);
        }
        return res;
    }
};