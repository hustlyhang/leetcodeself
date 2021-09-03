/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include <string>
#include <set>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 考虑双指针
        int ret = 0;
        int l = 0, r = 0;
        unordered_set<char> flg;
        while (r < s.size()) {
            if (flg.count(s[r]) == 0)
                flg.insert(s[r++]);
            else
                while (flg.count(s[r]))
                    flg.erase(s[l++]);
            ret = max(ret, r - l);
        }
        return ret;
    }
};
// @lc code=end

