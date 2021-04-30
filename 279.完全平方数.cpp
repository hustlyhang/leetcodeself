/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution
{
public:
    vector<int> getList(int n)
    {
        vector<int> ans;
        for (int i = 1; i <= n; ++i)
        {
            ans.push_back(i * i);
        }
        return ans;
    }
    int numSquares(int n)
    {
        vector<int> List = getList((int)sqrt(n));
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; ++i)
        {
            dp[i] = i;
        }

        for (int j = 1; j < List.size(); ++j)
        {
            int tmp = List[j];
            for (int i = tmp; i <= n; ++i)
            {
                dp[i] = min(dp[i], dp[i - tmp] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end
