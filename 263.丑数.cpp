/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    bool isUglyCore(int n) {
        while (n % 2 == 0) {
            n/=2;
        }
        while (n % 3 == 0) {
            n/=3;
        }
        while (n % 5 == 0) {
            n/=5;
        }
        if (n > 1) return false;
        else return true;
    }
    bool isUgly(int n) {
        if (n <= 0) return false;
        return isUglyCore(n);
    }
};
// @lc code=end

