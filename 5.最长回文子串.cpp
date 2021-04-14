/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子�?
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        if (s.size() == 2 && s[0] == s[1]) return s;
        int left = 0, right = 0;
        int maxlen = 0;
        vector<vector<int>> tmp(s.length(), vector<int>(s.length(), 1));
        // ??? ???????
        // j?i+1?? ??left?right???????
        for (int i = s.length() - 1; i >= 0; --i) {
            for (int j = i + 1; j < s.length(); ++j) {
                if(s[i] == s[j] && tmp[i + 1][j - 1] == 1) {
                    tmp[i][j] = 1;
                    if (j - i + 1> maxlen) {
                        maxlen = j - i + 1;
                        left = i;
                        right = j;
                        //cout<<"i="<<i<<";"<<"j="<<j<<endl;
                    }
                }
                else tmp[i][j] = 0;
            }
        }
        // ??right??????????
        return string(s.begin() + left, s.begin() + right + 1);
    }
};
// @lc code=end

