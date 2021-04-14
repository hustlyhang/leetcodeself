/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp;
    
    void subsetsWithDupCore(int i, vector<int> &nums, vector<bool> &assi)
    {
        ret.push_back(tmp);
        for (int j = i; j < nums.size(); ++j) {
            if (j > 0 && nums[j] == nums[j - 1] && assi[j - 1] == false) {
                continue;
            }
            tmp.push_back(nums[j]);
            assi[j] = true;
            subsetsWithDupCore(j + 1, nums, assi);
            tmp.pop_back();
            assi[j] = false;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0) return ret;
        sort(nums.begin(), nums.end());
        vector<bool> assi(nums.size(), false);
        subsetsWithDupCore(0, nums, assi);
        return ret;
    }
};
// @lc code=end

