/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
#include <algorithm>
using namespace std;

class Solution1 {
public:
    int mySqrt(int x) {
        int i = 0;
        long sum = 0;
        while (sum <= x) {
            i++;
            sum = pow(i, 2);
        }
        return i == 0 ? 0 : i - 1;
    }
    
};
//! 二分查找
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                //! 因为要找满足条件最大的那个值，所以小于等于
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end

