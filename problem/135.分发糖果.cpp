/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ret = 0;
        if (n == 0) return 0;
        if (n == 1) return 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) dp[i] = dp[i - 1] + 1;
        }
        vector<int> dp2(n, 1);
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) dp2[i] = dp2[i + 1] + 1;
        }
        for (int i = 0; i < n; ++i) {
            ret += max(dp[i], dp2[i]);
        }
        return ret;
    }
};
// @lc code=end

