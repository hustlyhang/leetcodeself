/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;
// https://leetcode-cn.com/problems/interleaving-string/solution/lei-si-lu-jing-wen-ti-zhao-zhun-zhuang-tai-fang-ch/

class Solution
{
public:
    // dp[i][j] 代表s1[i]和s2[j]结束得部分是否和s3[i + j - 1]结束得部分匹配
    bool isInterleave(string s1, string s2, string s3)
    {
        int len1 = s1.size(), len2 = s2.size();
        if (len1 + len2 != s3.size())
            return false;
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        // 初始化
        dp[0][0] = true;
        for (int i = 1; i <= len1; ++i)
        {
            if (s1[i - 1] == s3[i - 1])
                dp[i][0] = true;
            else
                break;
        }
        for (int j = 1; j <= len2; ++j)
        {
            if (s2[j - 1] == s3[j - 1])
                dp[0][j] = true;
            else
                break;
        }

        for (int i = 1; i <= len1; ++i)
        {
            for (int j = 1; j <= len2; ++j)
            {
                //
                if (s3[i + j - 1] == s1[i - 1])
                {
                    dp[i][j] = dp[i][j] | dp[i - 1][j];
                }
                if (s3[i + j - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i][j] | dp[i][j - 1];
                }
            }
        }
        return dp[len1][len2];
    }
};
// @lc code=end
