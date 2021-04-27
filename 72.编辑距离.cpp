/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int minDistance(string word1, string word2) {
        // vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() +
        // 1, 0));

        // //! 边界条件
        // for (int i = 0; i <= word1.size(); ++i) {
        //     dp[i][0] = i;
        // }
        // for (int j = 0; j <= word2.size(); ++j) {
        //     dp[0][j] == j;
        // }

        // for (int i = 1; i <= word1.size(); ++i) {
        //     for (int j = 1; j <= word2.size(); ++j) {
        //         if (word1[i - 1] == word2[j - 1]) {
        //             dp[i][j] = dp[i - 1][j - 1];
        //         }
        //         else {
        //             dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i -
        //             1][j - 1]) + 1;
        //         }
        //     }
        // }
        // return dp[word1.size()][word2.size()];

        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++)
            dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++)
            dp[0][j] = j;
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    //? 这儿dp[i][j - 1] 表示将i全部去匹配j-1，而j用插入一个来匹配
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

class test{
    public:
        int minDistance(string word1, string word2) {
            int len1 = word1.size(), len2 = word2.size();
            vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1,INT_MAX));
            for (int i = 0; i <= len1; ++i) dp[i][0] = i;
            for (int j = 1; j <= len2; ++j) dp[0][j] = j;

            for (int i = 1; i <= len1; ++i) {
                for (int j = 1; j <= len2; ++j) {
                    if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                    else {
                        //! dp[i - 1][j - 1]相当于替换当前字符，dp[i - 1][j]删除字符，dp[i][j - 1]插入字符
                        dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                    }
                }
            }
            return dp[len1][len2];
        }



};
// @lc code=end
