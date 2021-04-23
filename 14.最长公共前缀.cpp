/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int j = 0;
        while (strs[0][j] == strs[strs.size() - 1][j]) j++;
        return strs[0].substr(0, j);
    }
};
// @lc code=end

