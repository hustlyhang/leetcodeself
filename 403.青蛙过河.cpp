/*
 * @lc app=leetcode.cn id=403 lang=cpp
 *
 * [403] 青蛙过河
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = true;
        for (int i = 1; i < n; ++i) {
            if (stones[i] - stones[i - 1] > i) {
                return false;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int k = stones[i] - stones[j];
                if (k > j + 1) {
                    break;
                }
                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                if (i == n - 1 && dp[i][k]) {
                    return true;
                }
            }
        }
        return false;
    }
};

// class Solution1 {
// public:
//     bool canCross(vector<int>& stones) {
//         int len  = stones.size();
//         vector<vector<bool>> dp(len, vector<bool>(len, false));
//         dp[0][0] = true;
//         dp[0][1] = true;
//         for (int i = 1; i < len; ++i) {
//             for (int j = 0; j < i; ++j) {
//                 int dist = stones[i] - stones[j];
//                 dp[i][dist] = dp[j][dist] | dp[j][dist - 1] | dp[j][dist + 1];
//             }
//         }
        
//     }
// };
// @lc code=end

