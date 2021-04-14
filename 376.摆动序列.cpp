/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
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
//         dp[0][0] = 1; // ��nums[0] ��β�Ľ��򳤶�
//         dp[0][1] = 1; // ��nums[0] ��β�����򳤶�
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
        int curDiff = 0; // ��ǰһ�Բ�ֵ
        int preDiff = 0; // ǰһ�Բ�ֵ
        int result = 1;  // ��¼��ֵ����������Ĭ���������ұ���һ����ֵ
        for (int i = 1; i < nums.size(); i++) {
            curDiff = nums[i] - nums[i - 1];
            // ���ַ�ֵ
            if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};
// @lc code=end

