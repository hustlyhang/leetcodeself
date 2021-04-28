/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1,0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (i % 2 == 1) {
                for (int j = 1; j <= i /2; ++j) {
                    dp[i] += dp[i - j] * dp[j - 1];
                }
                dp[i]*=2;
                dp[i]+=(dp[i/2]*dp[i/2]);
            }
            else {
                for (int j = 1; j <= i / 2; ++j) {
                    dp[i] += dp[i - j] * dp[j - 1];
                }
                dp[i]*=2;
            }
        }
        return dp[n];
    }
};
// @lc code=end

