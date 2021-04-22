/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int len = s.size();
        vector<int> dp(len + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= len; ++i)
        {
            if (s[i - 1] != '0')
            {
                dp[i] += dp[i - 1];
            }
            if (s[i - 2] != '0' && (s[i - 2] - '0') * 10 + s[i - 1] - '0' <= 26)
            {
                dp[i] += dp[i - 2];
            }
        }
        return dp[len];
    }
};
// @lc code=end
