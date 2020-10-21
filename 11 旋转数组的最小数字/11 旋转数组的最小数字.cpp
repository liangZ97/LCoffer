#include<iostream>
#include<vector>
using namespace std;
/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。//注意这里输入的是一个原来有序的数组，我们可以利用二分查找法
例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  
*/
//二分查找法
class Solution {
public:
    int minArray(vector<int>& numbers) {
        // sort(numbers.begin(),numbers.end());
        // return numbers[0];
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int m = (i + j) / 2;
            if (numbers[m] > numbers[j]) i = m + 1;
            else if (numbers[m] < numbers[j]) j = m;
            else j--;
        }
        return numbers[i];

    }
};

int main() {
    vector<int> v = { 1,3,5 };
    int min = 1;
    if (min == Solution().minArray(v))
        cout << "test01 passed "<<endl <<"minmum number is "<< min << endl;
    else
        cout << "test01 failed" << endl;
    vector<int> v1 = { 3, 4, 5, 1, 2 };
    if (min == Solution().minArray(v))
        cout << "test02 passed " << endl<<"minmum number is " << min << endl;
    else
        cout << "test02 failed" << endl;
    return 0;
}