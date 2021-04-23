/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
  public:
    int bsearch(vector<int> nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] == target)
                return m;
            else if (nums[m] < target)
                l = m + 1;
            else
                r = m;
        }
        return -1;
    }
    /*  
     ! 每次查找，找到后仍往下找，即r = mid - 1，最后退出条件就是r = l - 1, 此时如果
     ! 找到了那么r肯定在数组中target所在位置的前一位，那么l就指向target的最左位置
     ! 如果数组中不存在target，那么就会像正常查找那样，r = l - 1时退出，所以在退出时要检查nums[l] == target
     ! 同时还要检查l是否越界
    */
    int searchleft(vector<int> nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] >= target) r = m - 1;
            else l = m + 1;
        }
        if (l == nums.size() || nums[l] != target) {
            return -1;
        }
        return l;
    }
    int searchright(vector<int> nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] <= target) l = m + 1;
            else r = m - 1;
        }
        if (r == -1 || nums[r] != target) {
            return -1;
        }
        return r;
    }
    vector<int> searchRange(vector<int> &nums, int target) {
        int m = bsearch(nums, target);
        vector<int> ret(2, -1);
        // if (m == -1)
        //     return ret;
        // else {
        //     int i = m;
        //     while (i >= 0 && nums[i] == target) {
        //         i--;
        //     }
        //     ret[0] = i + 1;
        //     i = m;
        //     while (i < nums.size() && nums[i] == target) {
        //         i++;
        //     }
        //     ret[1] = i - 1;
        // }
        // return ret;
        int l = searchleft(nums, target);
        if (l == -1) return ret;
        else {
            ret[0] = l;
            ret[1] = searchright(nums, target);
        }
        return ret;
    }
};
// @lc code=end
