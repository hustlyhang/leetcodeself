/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i - 1; ++j) {
                dp[i] = max({dp[i], j * dp[i - j], j*(i - j)});
            }
        }
        return dp[n];
    }
};
// @lc code=end

