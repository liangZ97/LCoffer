#include <iostream>
#include <vector>
#include<ctime>
using namespace std;
/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
*/
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> result;
        //打造一个滑动窗口，左闭右开 [ )。找出含有最小数的的多项式
        int i = 1;//滑动窗口的左边界
        int j = 1;//滑动窗口的左边界
        int sum = 0;
        while (i <= target / 2) {//当i>target时，滑动窗口不可能满足sum==target
            if (sum < target) {
                sum += j;
                ++j;
            }
            else if (sum > target) {
                sum -= i;
                ++i;
            }
            else {
                vector<int> vec;
                vec.clear();
                for (int a = i; a < j; a++) vec.emplace_back(a);
                result.emplace_back(vec);
                //继续向左移动，寻找合适的数组
                sum -= i;
                ++i;
            }
        }
        return result;
    }
};

int main() {
    srand((unsigned int)time(NULL));
    int target=rand()%10+5;
    //int target = 11;
    cout <<target <<endl;
    //注意！！！输出的是所有连续正整数序列
    //所以这里才能采用滑动窗口设计
    vector<vector<int>> result = Solution().findContinuousSequence(target);
    //int rows = result.size();
    for (int rows = 0; rows < result.size(); ++rows) {
        for (int cloumns = 0; cloumns < result[rows].size(); ++cloumns)
            cout << result[rows][cloumns] << " ";
        cout << endl;
    }
    return 0;
}