/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

/*
 * 思想：利用数组大小这个信息，将小于0的数字变为大于数组大小，表示这些数字都不可能
 * 然后遍历数组，将小于n的数字下标处都设置为负数，表示当前位置的数字出现过，最后从头遍历数
 * 组，找到正数的位置就是缺失的数字
 */
class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        for (int &num : nums) {
            if (num <= 0) {
                num = n + 1;
            }
        }
        // 因为要找的是未出现的最小的正数，所以对于大于数组大小的数字不用管
        // 所以将小于0的数字变为n+1
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        // 对每一个（0-n）的数字都在其对应下标处作记号，小于0
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        // 找到那个数字
        return n + 1;
    }
};

// @lc code=end
