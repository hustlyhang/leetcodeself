/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); ++i) {
            if (um.find(nums[i]) != um.end()) {
                return vector<int>{um[nums[i]],i};
            }
            else{
                um[target - nums[i]] = i;
            }
        }
        return vector<int>(2,-1);
    }
};
// @lc code=end

