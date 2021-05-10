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


class test{
  public:
    int numSquares(int n){
        vector<int> list;
        // 相当于有这么多个物品；
        for (int i = 1; i * i <= n; ++i) {
            list.push_back(i * i);
        }

        // 完全背包问题，
        vector<vector<int>> dp(list.size() + 1, vector<int>(n, -1));

        // 先考虑第一个物品，初始化
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = i;
        }
        // 考虑每一个物品
        for (int i = 1; i < list.size(); ++i) {
            for (int j = 0; j <= n; ++j) {
                // 只有当当前背包容量大于物品重量时才能放进去
                for (int k = 0; j >= k * list[i]; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - k * list[i]] + k);
                }
            }
        }
        return dp[list.size()][n];


    }



};      
// @lc code=end
