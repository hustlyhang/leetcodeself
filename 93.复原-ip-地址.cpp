/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> ret;
    string tmp;
    void restoreIpAddressesCore(int i, int count, string s) {
        if (i == s.length() && count == 4) {
            ret.push_back(tmp);
            return;
        }
        if ((count == 4 && i < s.length()) || (count < 4 && i == s.length())) return;
        if (4 - count > s.length() - i) return;
        if (s[i] == '0') {
            if (count == 0) tmp+="0";
            else tmp+=".0";
            restoreIpAddressesCore(i + 1, count + 1, s);
            if (count == 0) tmp.resize(tmp.size() - 1);
            else tmp.resize(tmp.size() - 2);
        }
        else {
            // 一位
            if (count == 0) tmp+=s[i];
            else tmp = tmp + '.' + s[i];
            restoreIpAddressesCore(i + 1, count + 1, s);
            if (count == 0) tmp.resize(tmp.size() - 1);
            else tmp.resize(tmp.size() - 2);
            //两位 先判断剩余位置是否有两位
            if (s.length() - i < 2) return;
            else {
                if (count == 0) tmp = tmp + s[i] + s[i + 1];
                else tmp = tmp + '.' + s[i] + s[i + 1];
                restoreIpAddressesCore(i + 2, count + 1, s);
                if (count == 0) tmp.resize(tmp.size() - 2);
                else tmp.resize(tmp.size() - 3);
            }
            //三位 先判断剩余位置是否有三位
            if (s.length() - i < 3) return;
            else {
                if ((s[i] - '0')*100 + (s[i + 1] - '0')*10 + (s[i + 2] - '0') <= 255){
                    if (count == 0) tmp = tmp + s[i] + s[i + 1] + s[i + 2];
                    else tmp = tmp + '.' + s[i] + s[i + 1] + s[i + 2];
                    restoreIpAddressesCore(i + 3, count + 1, s);
                    if (count == 0) tmp.resize(tmp.size() - 3);
                    else tmp.resize(tmp.size() - 4);
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.length() < 4) return ret;
        restoreIpAddressesCore(0, 0, s);
        return ret;
    }
};
// @lc code=end

