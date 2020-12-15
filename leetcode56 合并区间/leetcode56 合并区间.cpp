#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
给出一个区间的集合，请合并所有重叠的区间。
输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (!intervals.size()) return {};
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size();) {
            int j = i + 1;
            int R = intervals[i][1];
            while (j < intervals.size() && intervals[j][0] <= R) {
                R = max(R, intervals[j][1]);
                ++j;
            }
            res.push_back({ intervals[i][0],R });
            i = j;
        }
        return res;
    }
};