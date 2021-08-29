/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return 0;
        vector<int> dp(len, 0);
        int ans = 0;
        // if (nums[1] - nums[0] == nums[2] - nums[1]) {
        //     dp[2] = 1;
        //     ans += 1;
        // }
        for (int i = 2; i < len; ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = dp[i - 1] + 1;
                ans+=dp[i];
            }
        }
        return ans;
    }
};
// @lc code=end

