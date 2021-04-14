/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <vector> 
using namespace std;

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp;
    vector<bool> as;
    // vector<int> tmp;
    void permuteCore(int i, vector<int> &nums) {
        if (i == nums.size()) {
            ret.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); ++j) {
            swap(nums[i], nums[j]);
            permuteCore(i + 1, nums);
            swap(nums[i], nums[j]);
        }
    }
    void premuteCore2(int n, vector<int> &nums) {
        if (n == nums.size()) {
            ret.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (as[i]) {
                as[i] = false;
                tmp.push_back(nums[i]);
                premuteCore2(n + 1, nums);
                as[i] = true;
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) return ret;
        as.assign(nums.size(), true);
        // permuteCore(9, nums);
        premuteCore2(0, nums);
        return ret;
    }
};
// @lc code=end

