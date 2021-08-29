/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int pos = 0;
        int len = nums.size();
        if (len == 0) return -1;
        int tmp = nums[0];
        for (auto x : nums) {
            if (tmp == x) pos++;
            else {
                pos--;
            }
            if (pos <= 0) {
                //! 更换时记得更新pos
                tmp = x;
                pos = 1;
            }
        }
        return tmp;
    } 
};
// @lc code=end

