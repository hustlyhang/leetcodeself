/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int fst = 0, sec = 0, thr = 0;
        for (auto x : nums) {
            if (x == 0) fst++;
            else if (x == 1) sec++;
            else if (x == 2) thr++;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (fst) {
                nums[i] = 0;
                fst--;
                continue;
            }
            if (sec) {
                nums[i] = 1;
                sec--;
                continue;
            }
            if (thr) {
                nums[i] = 2;
                thr--;
                continue;
            }
        }
    }
};
// @lc code=end

