/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int l = 0, r = len - 1;
        while (l <= r) {
            int pos = Partition(nums, l, r);
            if (pos == len - k) {
                return nums[pos];
            }
            else if (pos < len - k) {
                l = pos + 1;
            }
            else {
                r = pos - 1;
            }
        }
        return 0;
    }
    int Partition(vector<int>& nums, int l, int r) {
        int tmp = nums[l];
        while (l < r) {
            while (l < r && nums[r] > tmp) r--;
            nums[l] = nums[r];
            while (l < r && nums[l] <= tmp) l++;
            nums[r] = nums[l];
        }
        nums[l] = tmp;
        return l;
    }
};

// todo 二分查找，快排等，等号问题
// @lc code=end

