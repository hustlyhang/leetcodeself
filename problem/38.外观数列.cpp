/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
  public:
    void deal(string &str) {
        char t = str[0];
        int i = 0, pos = 0;

        string tmp;
        while (i < str.size()) {
            while (i < str.size() && t == str[i]) {
                i++;
                pos++;
            }
            tmp.push_back(('0' + pos));
            tmp.push_back(str[i - 1]);
            pos = 0;
            t = str[i];
        }
        str = tmp;
    }
    string countAndSay(int n) {
        string str("1");
        while (--n) {
            deal(str);
        }
        return str;
    }
};
// @lc code=end
