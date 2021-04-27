/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
//! 回溯超时，需要使用动态规划
class Solution1 {
  public:
    int ans = 0;
    void dfs(vector<int> &nums, int target, int sum) {

        if (sum == target) {
            ans++;
            return;
        }
        if (sum > target)
            return;
        for (int i = 0; i < nums.size(); ++i) {
            dfs(nums, target, sum + nums[i]);
        }
    }
    int combinationSum4(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(nums, target, 0);
        return ans;
    }
};

class Solution {
  public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int &num : nums) {
                //? 需要判断是否超过范围  dp[i - num] < INT_MAX - dp[i]
                if (num <= i && dp[i - num] < INT_MAX - dp[i]) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};

// @lc code=end
