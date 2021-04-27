/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int i = 0;
        int l = newInterval[0], r = newInterval[1];
        while (i < intervals.size())
        {
            if (intervals[i][0] >= l)
                break;
            if (intervals[i][0] <= l && intervals[i][1] >= l)
                break;
            i++;
        }
        if (i == intervals.size())
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        // cout << "i =" << i << endl;
        int ansl = min(l, intervals[i][0]), ansr = r;
        int j = i;
        while (j < intervals.size())
        {
            if (r >= intervals[j][0])
            {
                ansr = max(ansr, intervals[j][1]);
            }
            else
                break;
            j++;
        }
        vector<vector<int>> ans;
        for (int k = 0; k < i; ++k)
        {
            ans.push_back(intervals[k]);
        }
        ans.push_back({ansl, ansr});
        for (int k = j; k < intervals.size(); ++k)
        {
            ans.push_back(intervals[k]);
        }
        return ans;
    }
};
// @lc code=end
