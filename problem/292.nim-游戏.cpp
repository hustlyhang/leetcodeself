/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        // vector<bool> dp(n + 1, false);
        // dp[1] = true;
        // dp[2] = true;        
        // dp[3] = true;
        // for (int i = 4; i <= n; ++i) {
        //     dp[i] = (!dp[i - 1]) | (!dp[i - 2]) | (!dp[i - 3]);
        // }        
        // return dp[n];
        return (n % 4 != 0);
    }
};
// @lc code=end

