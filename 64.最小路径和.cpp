/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int dp[cols];
        dp[0] = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 && j == 0) dp[j] = dp[j];
                else if (i == 0) {
                    dp[j] = dp[j - 1];
                }
                else if (j == 0) dp[j] = dp[j];
                else {
                    dp[j] = min(dp[j], dp[j - 1]);
                }
                dp[j] += grid[i][j];
            }
        }
        return dp[cols - 1];
    }
};
// @lc code=end

