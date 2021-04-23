/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution1 {
  public:
    int search1(vector<int> &nums, int target) {
        int flg = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i + 1 < nums.size() && nums[i] > nums[i + 1]) {
                flg = i + 1;
            }
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                // !注意需要取个余
                return (i + flg) % nums.size();
            }
        }
        return -1;
    }
};

// !二分查找
class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            //! 为什么是等号，不然当l==r时就不能更新了
            if (nums[l] <= nums[mid]) {
                //! 相当于判断左边是否是有序的，因为严格单调递增
                //! 所以和nums[0]比较
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    //! 不在有序这边
                    l = mid + 1;
                }
            } else {
                // ! 如果不在左边不是有序的，那么右边肯定是有序的
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    //! 不在有序这边
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

class practice {
  public:
    int s(vector<int> &nums, int target) {
        //! 特殊情况
        int len = nums.size();
        if (len == 1)
            return nums[0] == target ? 0 : -1;

        //! 开始二分查找
        int l = 0, r = len - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > nums[0]) {
                //! 如果中间不相等的话，就要判断左边还是右边有序，然后再更新l和r
                if (target >= nums[0] && target < nums[mid]) {
                    //! 如果target在这个范围内，那么就更新r
                    r = mid - 1;
                } else {
                    //! 如果target不在这个范围内，那么就更新r
                    l = mid + 1;
                }
            } else {
                //! 左边无序，那么右边肯定有序
                if (target <= nums[len - 1] && target > nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
