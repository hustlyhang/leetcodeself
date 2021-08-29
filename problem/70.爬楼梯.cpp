/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        int p = 1, q = 1;
        int ret = 1;
        for (int i = 2; i <= n; ++i) {
            ret = p + q;
            p = q;
            q = ret;
        }
        return ret;
    }
};
// @lc code=end

