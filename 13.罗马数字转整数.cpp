/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<char, int> m {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int romanToInt(string s) {
        int i = s.size() - 1;
        int flg = 1; //记录进位
        int ret = 0;
        int tmp = 0;
        while (i >= 0) {
            //? 多位相同
            while (i >= 0 && tmp < pow(10, flg)) {
                if (i - 1 >= 0 && m[s[i]] > m[s[i - 1]]) {
                    //? 说明是小加大可以直接退出当前循环，进入下一位
                    tmp+=m[s[i]];
                    tmp-=m[s[i - 1]];
                    i--;
                    i--;
                    break;
                }
                else {
                    tmp+=m[s[i]];
                    i--;
                }
            }
            flg++;
            ret+=tmp;
            tmp = 0;
        }
        return ret;
    }
};
// @lc code=end

