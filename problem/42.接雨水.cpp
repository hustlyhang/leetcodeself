/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right)
        {
            if (height[left] < height[right])  //! 相当于是选择最小的围栏，然后看周围的是不是比最高的低，是的话就加入结果，不是的话就更新最低（表示装不了水）
            {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else
            {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};

class test
{
public:
    int trap(vector<int> &height)
    {
        // 每次处理最小的边
        int l = 0, r = height.size() - 1;
        int maxl = 0, maxr = 0;
        int ret = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] < maxl) {
                    ret += maxl - height[l];
                    
                }
                else {
                    maxl = height[l];
                }
                l++;
            }
            else {
                if (height[r] < maxr) {
                    ret += maxr - height[r];
                    
                }
                else {
                    maxr = height[r];
                }
                r--;
            }
        }
        return ret;
    }
};

// @lc code=end
