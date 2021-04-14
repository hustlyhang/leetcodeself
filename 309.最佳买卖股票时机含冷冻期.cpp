/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻�?
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = -prices[0];
        dp[1][0] = 0;
        dp[1][1] = 0;
        dp[1][2] = max(-prices[0], -prices[1]);
        for (int i = 2; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 2][2] + prices[i - 1];
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] - prices[i]);
        }
        return max(dp[n - 1][2],max(dp[n - 1][0], dp[n - 1][1]));
    }
};
// @lc code=end

