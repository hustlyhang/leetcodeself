/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        //? 这儿直接反转是因为交换两个数字后，后面部分仍然有序
        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end
