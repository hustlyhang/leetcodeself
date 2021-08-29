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

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int fst = newInterval[0], sec = newInterval[1];
        int l = 0, r = intervals.size() - 1;
        bool flg = true;

        // 将特殊情况分开讨论
        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        if (sec < intervals[0][0]) {
            intervals.insert(intervals.begin(), {fst, sec});
            return intervals;
        }
        if (fst > intervals[intervals.size() - 1][1]) {
            intervals.push_back(newInterval);
            return intervals;
        }
        for (int i = 0; i < intervals.size(); ++i) {
            if ((intervals[i][0] >= fst || intervals[i][1] >= fst) && flg) {
                l = i;
                flg = false;
            }
            if (intervals[i][0] > sec) {
                r = i - 1;
                break;
            }
            if (intervals[i][1] >= sec) {
                r = i;
                break;
            }
        }
        fst = min(fst, intervals[l][0]);
        sec = max(sec, intervals[r][1]);
        // cout<<"fst = " <<fst;
        // cout<<"sec = " <<sec;
        intervals.erase(intervals.begin() + l, intervals.begin() + r + 1);
        intervals.insert(intervals.begin() + l, {fst, sec});
        return intervals;
    }
};
// @lc code=end
