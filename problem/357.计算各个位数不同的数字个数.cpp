/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个�?
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        int num = min(10, n);
        vector<int> dp(num + 1, 0);
        dp[0] = 1;
        dp[1] = 9;
        int sum = dp[0] + dp[1];
        for (int i = 2; i <= num; ++i) {
            int ass = 9;
            for (int j = 1; j < i; ++j) {
                ass*=(9 - j + 1);
            }
            dp[i] = sum + ass;
            sum = dp[i];
        }
        return dp[n];
    }
};
// @lc code=end

