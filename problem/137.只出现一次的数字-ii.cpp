/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i <= 31; ++i) {
            int tmp = 0;
            for (int j = 0; j < nums.size(); ++j) {
                tmp += ((nums[j]>>i) & 1);
                
            }
            if (tmp % 3) 
                {
                    ans |= (1 << i);
                }
        }
        return ans;
    }
};
// @lc code=end

