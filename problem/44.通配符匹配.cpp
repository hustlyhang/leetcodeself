/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = true;
            } else {
                break;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    //? 这儿 j - 1 意味着忽略这个*， i -
                    // 1代表任意匹配s中的字符相当于取决于前一个的结果，忽略当前这个s[i]
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                    // dp[i][j] = true;
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
class test {
  public:
    bool isMatch(string s, string p) {
        int len1 = s.size(), len2 = p.size();
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        // 初始化
        dp[0][0] = true;
        for (int j = 1; j <= len2; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = true;
            }
            else break;
        }
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                else {
                    if (p[j - 1] == '*') dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                } 
            }
        }
        return dp[len1][len2];
    }
};
// @lc code=end
