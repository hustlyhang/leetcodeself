/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int p = partition(nums, l, r);
        quickSort(nums, l, p - 1);
        quickSort(nums, p + 1, r);
    }
    int partition(vector<int>& nums, int l, int r) {
        int s = rand() % (r - l + 1);
        swap(nums[l], nums[l + s]);
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
// @lc code=end

