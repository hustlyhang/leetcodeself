/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return nums[0] == target;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                ++l;
                --r;
            } else if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};



// 和I的区别在于判断时需要多判断一下，两边l和r的数字和m的值是不是相等，相等的话就要将两边缩短
class practice {
public:
    bool search(vector<int> &nums, int target) {
        //! 首先特殊情况
        int len = nums.size();
        if (len == 0) return false;
        if (len == 1) return nums[0] == target;

        //! 开始二分
        int l = 0, r = len - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            //! 第一种情况 相等
            if (nums[m] == target) {
                return true;
            } else if (nums[m] == nums[l] && nums[m] == nums[r]) {
                //! 说明无法判断两边， 哪一边有序 就将两边缩小，因为首先判断了nums[m] == target
                //! 所以可以将两边都缩小
                l++;
                r--;
                
            } else if (nums[m] >= nums[l]) {
                //! 左边有序， 注意m的比较，是大于等于
                if (target >= nums[l] && target < nums[m]) {
                    r = m - 1;
                }else {
                    l = m + 1;
                }
            }else {
                //! 右边有序
                if (target <= nums[r] && target > nums[m]) {
                    l = m + 1;
                }else {
                    r = m - 1;
                }
            }
        }
        return false;
    }
};
// @lc code=end

