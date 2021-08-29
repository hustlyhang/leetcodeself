/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 涓嶇浉浜ょ殑绾?
 */

// @lc code=start
#include <vector>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // dp[i][j] 代表最长公共子序列
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

