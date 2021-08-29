/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid = 0;
        // !注意二分查找的条件是等号 说明是左闭右闭区间, 区间不一样， 那么修改边界的时候也不一样
        while (left < right)
        {
            mid = (left + right) >> 1;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid; // *当改为左闭右开区间时，right的修改就不一样了
            else return mid;
        }
        return -1;
    }
};
// @lc code=end

