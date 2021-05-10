/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPowCore(double x, long n) {
        if (n == 0) return 1;
        if (n % 2 == 1) {
            return x * myPowCore(x * x, n / 2);
        }
        else {
            return myPowCore(x * x, n / 2);
        }
    }
    double myPow(double x, int n) {
        bool sign = 1;
        long tmp = n;
        if (n < 0) {
            sign = 0;
            tmp = -tmp;
        }
        if (sign == 0) return (double)1/myPowCore(x,tmp);
        return myPowCore(x, tmp);
    }
};
// @lc code=end

