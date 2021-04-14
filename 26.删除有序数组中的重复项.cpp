/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int me = 0;
        int len = nums.size();
        if (len < 2) return len;
        for (int i = 1; i < len; ++i) {
            if (nums[i] == nums[i - 1]) me++;
            nums[i - me] = nums[i];
        }
        return len - me;
    }
};
// @lc code=end

