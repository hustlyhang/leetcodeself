/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    static bool cmp(vector<int> a, vector<int> b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    //! 注意排序的规则按照开始点递增排序，如果开始点相同就按照结束点递减排序，方便覆盖
    //! 因为后面比较时为 intervals[i][0] <= end 所以相同的start要将end最大的放在前面，其实都行
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0)
            return result;
        sort(intervals.begin(), intervals.end(), cmp);
        int length = intervals.size();
        int i = 0;
        while (i < length) {
            int start = intervals[i][0]; // 初始为i-1区间的左边界
            int end = intervals[i][1];   // 初始i-1区间的右边界
            while (i < length && intervals[i][0] <= end) { // 合并区间
                end = max(end, intervals[i][1]); // 不断更新右区间
                i++; // 继续合并下一个区间
            }
            result.push_back({start, end});
        }
        return result;
    }
};
// @lc code=end
