/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 鎽嗗姩搴忓垪
 */

// @lc code=start
#include <vector>
using namespace std;

// class Solution {
// public:
//     vector<vector<int>> dp;
//     int wiggleMaxLength(vector<int>& nums) {
//         if (nums.size() <= 1) return nums.size();
//         dp.assign(nums.size(),vector<int>(2, 1));
//         dp[0][0] = 1; // 以nums[0] 结尾的降序长度
//         dp[0][1] = 1; // 以nums[0] 结尾的升序长度
//         int ret = 1;
//         for (int i = 1; i < nums.size(); ++i) {
//             if (nums[i] > nums[i - 1]) {
//                 dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][1]);
//             }
//             else if (nums[i] < nums[i - 1]) dp[i][0] = max(dp[i - 1][1] + 1, dp[i - 1][0]);
//             else {
//                 dp[i][0] = dp[i - 1][0];
//                 dp[i][1] = dp[i - 1][1];
//             }
//         }
//         return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
//     }
// };

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0; // 当前一对差值
        int preDiff = 0; // 前一对差值
        int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值
        for (int i = 1; i < nums.size(); i++) {
            curDiff = nums[i] - nums[i - 1];
            // 出现峰值
            if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};
// @lc code=end

