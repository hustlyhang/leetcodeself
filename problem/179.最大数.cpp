/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start

#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    static bool cmp(const int a, const int b) {
        string s1 = to_string(a);
        string s2 = to_string(b);
        int len1 = s1.size(), len2 = s2.size();
        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            if (s1[i] < s2 [j]) return false;
            else if (s1[i] > s2 [j]) return true;
            else {
                i++;
                j++;
                continue;
            }
            
        }
        string tmp1 = s1 + s2;
        string tmp2 = s2 + s1;
        return tmp1 > tmp2;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ret;
        if (nums[0] == 0) return string{"0"};
        else {
            for (auto x : nums) {
                ret += to_string(x);
            }
        }
        
        return ret;
    }
};
// @lc code=end

