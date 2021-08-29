/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        digits[len - 1] += 1;
        vector<int> ans;
        int pos = 0;
        for(int i = len - 1; i >= 0; --i) {
            ans.push_back((pos + digits[i])%10);
            pos = (pos + digits[i])/10;
        }
        if (pos) ans.push_back(pos);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

