/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文�?
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> ret;
    vector<string> tmp;
    vector<vector<bool>> flg;
    void partitionCore(string s, int i) {
        if (i == s.length()) {
            ret.push_back(tmp);
        }
        else {
            for (int j = i; j < s.length(); ++j) {
                if (flg[i][j]) {
                    tmp.push_back(s.substr(i, j - i + 1));
                    partitionCore(s, j + 1);
                    tmp.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int len = s.length();
        flg.assign(len, vector<bool>(len, true));
        // 初始化回文字符串
        for (int i = len - 1; i >= 0; --i) {
            for (int j = i + 1; j < len; ++j) {
                flg[i][j] = s[i] == s[j] && flg[i + 1][j - 1];
            }
        }
        partitionCore(s, 0);
        return ret;
    }
};
// @lc code=end

