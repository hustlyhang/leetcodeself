/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        vector<int> dp(n, 1);
        int ret = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
// @lc code=end

