/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132模式
 */

// @lc code=start
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int two = INT_MIN;

        stack<int> s;
        int n = nums.size();
        for (int i = n-1; i >=0; --i)
        {
            // 找到比2小的数字，那么满足条件
            if (nums[i] >= two)
            {
                // 如果发现大于最大栈，那么要去更新栈和two的数值（two变为更大的数字）
                while (!s.empty() && nums[s.top()] < nums[i])
                {
                    two = nums[s.top()];
                    s.pop();
                }
                s.push(i);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

// @lc code=end

