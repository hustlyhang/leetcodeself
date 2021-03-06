/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int ans = 0;
        int i = 0, j = 0;
        while (j < s.size()) {
            while (j < s.size() && us.find(s[j]) == us.end()) {
                us.insert(s[j]);
                j++;
            }
            ans = max(ans, j - i);
            us.erase(us.find(s[i]));
            i++;
        }
        return ans;
    }
};

class test{
    int lengthOfLongestSubstring(string s) {
        // 双指针
        int ret = 0;
        int l = 0, r = 0;
        unordered_set<char> us;
        while (r < s.size()) {
            while (r < s.size() && us.count(s[r]) == 0) {
                us.insert(s[r]);
                r++;
            }
            ret = max(ret, r - l);
            while (l <= r && us.count(s[r])) {
                us.erase(s[l]);
                l++;
            }
        }
        return ret;
    }


};
// @lc code=end

