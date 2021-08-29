/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
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
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return n;
        sort(points.begin(), points.end(), cmp);
        int ret = 0;
        int i = 0;
        while (i < n) {
            int right = points[i][1];
            while (i < n && points[i][0] <= right){
                i++;
            }
            ret++;
        }
        return ret;
    }
};
// @lc code=end

