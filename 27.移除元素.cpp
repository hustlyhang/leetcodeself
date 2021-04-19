/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>
using namespace std;
 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos = 0;
        for (int i = 0; i < nums.size(); ++i) {
            
            if (nums[i] == val) {
                pos++;
            }
            else {
                nums[i - pos] = nums[i];
            }
            
        }
        return nums.size() - pos;
    }
};
// @lc code=end

