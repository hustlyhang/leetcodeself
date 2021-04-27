/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> flg;
    int t = 0;
    int sum = 0;
    vector<int> nums;
    string ans;
    void dfs(int start)
    {
        if (start == flg.size())
        {
            sum++;
            if (sum == t)
            {
                for (auto x : nums)
                {
                    ans += to_string(x);
                }
                return;
            }
        }
        for (int i = 0; i < flg.size(); ++i)
        {
            if (flg[i] && sum < t)
            {
                nums.push_back(i + 1);
                flg[i] = false;
                dfs(start + 1);
                nums.pop_back();
                flg[i] = true;
            }
        }
    }

    string getPermutation(int n, int k)
    {
        flg.assign(n, true);
        t = k;
        dfs(0);
        return ans;
    }
};

class Solution1
{
public:
    string getPermutation(int n, int k)
    {
        //? 第一个数字固定后，有(n - 1)! 种情况
        int t = n, m = k;
        vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
        //? 获得阶乘
        int tmp = 1;
        vector<int> tt;
        tt.push_back(1);
        tt.push_back(tmp);
        for (int i = 2; i <= n; ++i)
        {
            tt.push_back(i * tt[i - 1]);
        }

        string ans;
        while (t)
        {
            t = t - 1;
            ans += ('0' + nums[(m - 1) / tt[t]]);
            int mmm = m;
            //! 每次更新m是减去前面的，而不是取余
            m = m - ((m - 1) / tt[t]) * tt[t];
            if (m == 0)
                m = 1;
            nums.erase(nums.begin() + (mmm - 1) / tt[t]);
        }
        return ans;
    }
};
// @lc code=end
