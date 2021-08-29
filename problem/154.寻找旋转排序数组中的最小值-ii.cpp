/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool isSequence(vector<int>& nums, int start, int end) {
        int tmp = nums[start];
        for (int i = start; i <= end; ++i) {
            if (tmp <= nums[i]) {
                tmp = nums[i];
            }
            else return false;
        }
        return true;
    }

    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if (isSequence(nums, 0, nums.size() - 1)) return nums[0];
        //! 为什么是小于
        //? 左闭右开区间 
        while (l < r) {
            int m = (l+ r) >> 1;
            //! 为什么等于m而不是m+1
            //? 因为时左闭右开区间，所以r = m 右边取不到r，所以用 = m
            if (nums[m] < nums[nums.size() - 1]) {
                r = m;
            }
            else if (nums[m] > nums[nums.size() - 1]) {
                l = m + 1;
            }
            else {
                if (isSequence(nums, 0, m)) l = m + 1;
                else r = m;
            }
        }
        return nums[l];
    }
};
// @lc code=end

