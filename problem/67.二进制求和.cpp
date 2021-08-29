/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
#include <string>
using namespace std;

class Solution1 {
public:
    string addBinary(string a, string b) {
        string ans;
        int len1 = a.size() - 1, len2 = b.size() - 1;
        int pos = 0;
        while (len1 >= 0 && len2 >= 0) {
            ans.push_back('0' + ((pos + a[len1] - '0' + b[len2] - '0') % 2));
            pos = (pos + a[len1] - '0' + b[len2] - '0') / 2;
            len1--;
            len2--;
        }
        while (len1 >= 0) {
            ans.push_back('0' + ((pos + a[len1] - '0') % 2));
            pos = (pos + a[len1] - '0') / 2;
            len1--;
        }
        while (len2 >= 0) {
            ans.push_back('0' + ((pos + b[len2] - '0') % 2));
            pos = (pos + b[len2] - '0') / 2;
            len2--;
        }
        if (pos) ans.push_back('0' + pos);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int len1 = a.size() - 1, len2 = b.size() - 1;
        int pos = 0, oft = 0;
        while (len1 >= 0 || len2 >= 0) {
            oft = 0;
            if (len1 >= 0) oft += a[len1] - '0';
            if (len2 >= 0) oft += b[len2] - '0';
            ans.push_back('0' + ((pos + oft) % 2));
            pos = (pos +oft) / 2;
            len1--;
            len2--;
        }
        if (pos) ans.push_back('0' + pos);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

