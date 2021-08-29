/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        if (len <= 1) return len;
        int ret = 0;
        vector<vector<bool>> dp(len, vector<bool>(len, true));
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j < len; ++j) {
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                if (dp[i][j]) ret++;
            }
        }
        ret += len;
        return ret;
    }
};
// @lc code=end

