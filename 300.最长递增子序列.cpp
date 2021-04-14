/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序�?
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        vector<int> dp(n, 1);
        int ret = 0;
        for(int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            ret = max(ret, dp[i]);
            }
            // cout<<dp[i]<<endl;
        }
        return ret;
    }
};
// @lc code=end

