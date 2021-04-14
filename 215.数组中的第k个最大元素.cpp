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
    int quickSort(vector<int> &nums, int l, int r) {
        int tmp = nums[l];
        int tl = l, tr = r;
        while (tl < tr) {
            while (tl < tr && nums[tr] > tmp) tr--;
            nums[tl] = nums[tr];
            //! 注意从左往右时，为小于等于，因为取的第一个为基准
            while (tl < tr && nums[tl] <= tmp) tl++;
            nums[tr] = nums[tl];
        }
        nums[tl] = tmp;
        return tl;
    }
    int findKthLargestCore(vector<int>& nums, int k, int l, int r) {
        int partition = quickSort(nums, l, r);
        // cout << partition <<endl;
        if (partition < k)  return findKthLargestCore(nums, k, partition + 1, r);
        else if (partition > k) return findKthLargestCore(nums, k, l, partition - 1);
        else return nums[partition];
    }
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargestCore(nums, nums.size() - k, 0, nums.size() - 1);
    }
};

class test{
    int ret = 0;
    void quickSort(vector<int>& nums, int k, int l, int r) {
        int tmp = nums[l];
        int tl = l, tr = r;
        while (tl < tr) {
            while (tl < tr && nums[tr] > tmp) tr--;
            nums[tl] = nums[tr];
            while (tl < tr && nums[tl] <= tmp) tl++;
            nums[tr] = nums[tl];
        }
        nums[tl] = tmp;
        if (tl < k) {
            quickSort(nums, k, tl + 1, r);
        }
        else if (k < tl) {
            quickSort(nums, k, l, tl - 1);
        }
        else {
            ret = tl;
            return;
        }
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        //! 第k大，那么 就是 nums.size() - k 小？nums.size() - k为下标
        k = nums.size() - k;
        quickSort(nums, k, 0, nums.size() - 1);
        return nums[ret];
    }
};
//! 堆排序待写
// @lc code=end

