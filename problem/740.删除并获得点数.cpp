/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        // 应该是从大删到小
        vector<pair<int, int>> nm;
        int sum = 0, tmp = nums[0];
        int i = 0;
        while (i < nums.size()) {
            while (i < nums.size() && nums[i] == tmp) {
                i++;
                sum++;
            }
            nm.push_back({tmp, sum});
            sum = 0;
            tmp = nums[i];
        }
        // for (auto x : nm) cout<<x.first<<' '<<x.second<<endl;
        int ret = 0;
        vector<int> dp(nm.size() + 1, 0);

        dp[1] = nm[0].first * nm[0].second;
        
        ret = max(ret, dp[1]);
        for (int i = 2; i <= nm.size(); ++i) {
            if (nm[i - 1].first == nm[i - 2].first - 1)
                dp[i] = max(dp[i - 2] + nm[i - 1].first * nm[i - 1].second,dp[i - 1]);
            else dp[i] = nm[i - 1].first * nm[i - 1].second + dp[i - 1];
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
// @lc code=end

