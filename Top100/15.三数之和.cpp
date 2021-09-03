/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    //! TLE
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int len = nums.size();
    //     if (len < 3) return {};
    //     sort(nums.begin(), nums.end());
    //     vector<vector<int>> ret;
    //     for (int i = 0; i < nums.size() - 2; ++i) {
    //         if (nums[i] > 0) break;
    //         if (i - 1 >= 0 && nums[i] == nums[i - 1]) continue;
    //         for (int j = i + 1; j < nums.size() - 1; ++j) {
    //             if (nums[i] + nums[j] > 0) break;
    //             if (j - 1 > i && nums[j] == nums[j - 1]) continue;
    //             for (int k = j + 1; k < nums.size(); ++k) {
    //                 if (nums[i] + nums[k] + nums[j] > 0) break;
    //                 else if (nums[i] + nums[k] + nums[j] == 0) {
    //                     ret.push_back({nums[i], nums[j], nums[k]});
    //                     while (k + 1 < nums.size() && nums[k] == nums[k + 1]) k++;
    //                 }
    //             }
    //         }
    //     }
    //     return ret;
    // }
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> ret;
        sort(num.begin(), num.end());
        if (num.size() <= 2) return ret; 
        int i = 0, j = 0, k = 0;
        while (i < num.size() - 2) {
            if (num[i] > 0) break;
            // 去重
            while (i > 0 &&  i < num.size() - 2 && num[i] == num[i - 1]) i++;
            j = i + 1;
            k = num.size() - 1;
            int sum = 0 - num[i];
            while (j < k) {
                if (num[j] + num[k] < sum) j++;
                else if (num[j] + num[k] > sum) k--;
                else {
                    ret.push_back({num[i],num[j],num[k]});
                    //去重
                    j++;
                    k--;
                    while (j < k && num[j] == num[j - 1]) j++;
                    while (j < k && num[k] == num[k + 1]) k--;
                }
            }
            i++;
        }
        return ret;
    }
};
// -4 -1 -1 0 1 2
// @lc code=end

