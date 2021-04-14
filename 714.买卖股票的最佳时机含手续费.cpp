/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 涔板崠鑲＄エ鐨勬渶浣虫椂鏈哄惈鎵嬬画璐?
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // dp[i][0] 表示第i天手里没有股票 dp[i][1]代表手里有股票
        // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + price[i] - 2)
        // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - price[i]);
        int n = prices.size();
        if (n <= 1) return 0;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        //return max(dp[n - 1][1], dp[n -1][0]);
        return dp[n -1][0];

    }
};
// @lc code=end

