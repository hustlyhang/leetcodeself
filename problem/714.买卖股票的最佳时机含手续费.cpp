/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续�?
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // dp[i][0] ��ʾ��i������û�й�Ʊ dp[i][1]���������й�Ʊ
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

