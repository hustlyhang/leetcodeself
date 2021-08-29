/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        unordered_set<string> m;
        for (auto x : wordDict) {
            m.insert(x);
        }
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] = dp[j] && m.find(s.substr(j, i - j)) != m.end();
                if (dp[i]) break;
            }
        }
        return dp[len];
    }
};
// 下标从零开始 ，而且一旦找到满足就要跳出循环
// @lc code=end

