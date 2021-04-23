/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0 || x/10 == 0) return true;
        if (x%10 == 0) return false;
        int tmp = 0;
        while (tmp < x) {
            int pos = x%10;
            tmp = tmp * 10 + pos;
            x/=10;
        }
        
        return ((tmp==x) |(tmp/10 == x));
    }
};
// @lc code=end

