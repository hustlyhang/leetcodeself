/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        if (len1 == 0 || len2 == 0)
            return 0;
        vector<int> nums(len1 + len2, 0);
        for (int i = len1 - 1; i >= 0; --i) {
            for (int j = len2 - 1; j >= 0; --j) {
                nums[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        //? 处理数组中的数字
        for (int i = nums.size() - 1; i > 0; --i) {
            nums[i - 1] += nums[i] / 10;
            nums[i] %= 10;
        }
        string ans;
        int i = 0;
        while (i < nums.size() && nums[i] == 0)
            i++;

        for (; i < nums.size(); ++i) {
            // cout << nums[i] << endl;
            ans.push_back(('0' + nums[i]));
        }
        if (ans.size() == 0)
            return "0";
        return ans;
    }
};
// @lc code=end
