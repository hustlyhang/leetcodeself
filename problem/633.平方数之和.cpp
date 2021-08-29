/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
#include <math.h>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    bool judgeSquareSum(int c) {
        double tc = sqrt(c);
        for (long long i = 0; i <= tc; ++i) {
            // 选择a
            if ((long long)i*i == c) return true;
            double j = (int)tc - i + 1;
            while (j < i + (int)tc) {
                if (i*i + j*j == c) return true;
                j++;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            double b = sqrt(c - a * a);
            //! 注意这儿的用法
            if (b == (int)b) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

