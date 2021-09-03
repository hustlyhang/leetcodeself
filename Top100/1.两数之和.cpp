/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(nums[i]) == 0) {
                m.insert({target - nums[i], i});
            }
            else {
                return {i, m[nums[i]]};
            }
        }
        return {};
    }
};
// @lc code=end

