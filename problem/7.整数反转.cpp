/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while (x) {
            int pos = x%10;
            x/=10;
            if (ret > INT_MAX/10 || (ret == INT_MAX/10 && pos > INT_MAX%10)) {
                return 0;
            }
            if (ret < INT_MIN/10 || (ret == INT_MIN/10 && pos < INT_MIN%10)) {
                return 0;
            }
            ret = ret*10 + pos;
        }
        return ret;
    }
};
// @lc code=end

