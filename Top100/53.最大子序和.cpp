/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp[i] 以i结尾的连续字数组的最大和
        // dp[i] = (dp[i - 1] + nums[i], nums[i])
        int ret = INT_MIN;
        int tmp = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            tmp = max((tmp + nums[i - 1]), nums[i - 1]);
            ret = max(tmp, ret);
        }
        return ret;
    }
};
// @lc code=end

