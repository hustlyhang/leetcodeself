/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[1] == b[1]) return a[0] > b[0];
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int ret = 0;
        int i = 0;
        while(i < n) {
            int right = intervals[i++][1];
            while (i < n && intervals[i][0] < right) i++;
            if (i == n) break;
            ret++;
        }
        return n - ret - 1;
    }
};
// @lc code=end

