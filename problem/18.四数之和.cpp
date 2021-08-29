/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;
        int fst = 0;
        sort(nums.begin(), nums.end());
        for (; fst < nums.size() - 3; ++fst) {
            if (fst > 0 && nums[fst] == nums[fst - 1]) continue;
            if (nums[fst] + nums[fst + 1] + nums[fst + 2] + nums[fst + 3] > target) break;
            if (nums[fst] + nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3] < target) continue;
            for (int sec = fst + 1; sec < nums.size() - 2; ++sec) {
                if (sec > fst + 1 && nums[sec] == nums[sec - 1]) continue;
                if (nums[fst] + nums[sec] + nums[sec + 1] + nums[sec + 2] > target) break;
                if (nums[fst] + nums[sec] + nums[nums.size() - 1] + nums[nums.size() - 2] < target) continue;
                int thr = sec + 1, fou = nums.size() - 1;
                while (thr < fou){
                    if (nums[fst] + nums[sec] + nums[thr] + nums[fou] == target) {
                        ans.push_back({nums[fst] , nums[sec] , nums[thr] , nums[fou]});
                        thr++;
                        fou--;
                        while (thr < fou && nums[thr] == nums[thr - 1]) thr++;
                        while (thr < fou && nums[fou] == nums[fou + 1]) fou--;
                    }
                    else if (nums[fst] + nums[sec] + nums[thr] + nums[fou] < target) thr++;
                    else fou--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

