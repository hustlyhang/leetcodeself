/*
 * @lc app=leetcode.cn id=1482 lang=cpp
 *
 * [1482] 制作 m 束花所需的最少天数
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
// 二分查找
class Solution {
public:
    bool make(vector<int>& bloomDay, int m, int k, int day) {
        int flowers = 0,tmpm = 0;
        for (int i = 0; i < bloomDay.size(); ++i) {
            if (bloomDay[i] < day) {
                flowers++;
                if (flowers == k){
                    flowers = 0;
                    tmpm++;
                    if (tmpm == m) return true;
                }
            }
            else {
                flowers = 0;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < m * k) return -1;
        int maxa = *max_element(bloomDay.begin(), bloomDay.end());
        int l = 1;
        while (l <= maxa) {
            int mid = l + ((maxa - l) >> 1);
            bool flg = make(bloomDay, m, k, mid);
            if (flg) maxa = mid - 1;
            else l = mid + 1;
        }
        // 为什么是maxa
        return maxa;
    }
};
// @lc code=end

