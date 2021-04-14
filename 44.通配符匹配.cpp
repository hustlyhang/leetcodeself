/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;


class Solution1 {
public:
    bool isMatch(string s, string p) {
        int len1 = s.size(), len2 = p.size();
        if ((len1 == 0 && len2 == 0) || (len1 == 0 && len2 == 1 && p[0] == '*')) return true;
        if (len1 == 0) {
            for (int j = 0; j < len2; ++j) {
                if (p[j] != '*') break;
            }
            return true;
        }
        if (len2 == 0) return false;
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1,false));
        dp[0][0] = true;
        if (p[0] == '*') {
            for (int j = 0; j < len2; ++j) {
                dp[0][j] = true;
            }
        }
        
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                //? 如果这两个位置匹配，就取决于前面一位
                if (s[i] == p[j]) dp[i + 1][j + 1] = dp[i][j];
                else {
                    //? 不匹配，那么就分为两种情况
                    //* 第一中模式串中不是特殊字符
                    if (p[j] != '*' && p[j] != '?') {
                        //? 那么当前位置不匹配就为false
                        dp[i + 1][j + 1] = false;
                    }
                    else {
                        //* 第二种情况
                        if(p[j] == '?') {
                            dp[i + 1][j + 1] = dp[i][j];
                        }
                        else if (p[j] == '*') {
                            dp[i + 1][j + 1] = false;
                            for (int k = i; k >=0;--k) {
                                if (dp[k][j]) {
                                    dp[i + 1][j + 1] = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        return dp[len1][len2];
        
    }
};


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = true;
            }
            else {
                break;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    //? 这儿 j - 1 意味着忽略这个*， i - 1代表任意匹配s中的字符相当于取决于前一个的结果，忽略当前这个s[i]
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

