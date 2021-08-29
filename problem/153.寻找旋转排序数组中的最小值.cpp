/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 瀵绘壘鏃嬭浆鎺掑簭鏁扮粍涓殑鏈�灏忓�?
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            //! 当中值比左值大时，都要往右移，等号的目的是为了当只有两个数字时可以更新l
            if (nums[m] >= nums[0]) {
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        //cout<<l<<endl;
        if (l == nums.size()) return nums[0];
        return nums[l];
    }
};
// @lc code=end

