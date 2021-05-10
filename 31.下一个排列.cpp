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


class test{
  public:
    void nextPermutation(vector<int> &nums) {
        // 从后往前找到那个降低的位置
        // 然后交换当前位置和后面刚好大于此位置的数字
        int len = nums.size();
        if (len == 1) return;
        int pos = -1;
        for (int i = len - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                pos = i - 1;
                break;
            }
        }
        //cout<<"pos = "<<pos<<endl;
        if (pos == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = len - 1; i >= 0; --i) {
            if (nums[i] > nums[pos]) {
                //cout<<"i = "<<i<<endl;
                swap(nums[pos], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + pos + 1, nums.end());
        return;
    }
};
// @lc code=end
