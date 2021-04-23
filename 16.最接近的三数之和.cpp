/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //! 定一移二
        sort(nums.begin(), nums.end());
        int fst = 0, sec = 0, thr = nums.size() - 1;
        int ret = 100000;
        int tmp = 0;
        while (fst < thr - 1) {
            thr = nums.size() - 1;
            sec = fst + 1;
            while (sec < thr) {
                ret = abs(nums[fst] + nums[sec] + nums[thr] - target) > abs (ret - target) ? ret : nums[fst] + nums[sec] + nums[thr];
                if (nums[fst] + nums[sec] + nums[thr] <= target) {
                    sec++;
                }
                else {
                    thr--;
                }
            }
            fst++;
            
        }
        return ret;
    }
};
// @lc code=end

