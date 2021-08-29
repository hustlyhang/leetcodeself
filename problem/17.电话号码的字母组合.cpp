/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> ret;
    string tmp;
    map<char, string> makeMap(){
        map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        return m;
    }
    void letterCombinationsCore(int i, string& digits, map<char, string>& m) {
        if (i == digits.length()) {
            ret.push_back(tmp);
            return;
        }
        else {
            for (auto c : m[digits[i]]) {
                tmp.push_back(c);
                letterCombinationsCore(i + 1, digits, m);
                tmp.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return ret;
        map<char, string> m = makeMap();
        letterCombinationsCore(0, digits, m);
        return ret;
    }
};
// @lc code=end

