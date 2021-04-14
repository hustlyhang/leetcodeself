/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

// class Solution {
// public:
//     int findLength(vector<int>& A, vector<int>& B) {
//         int ret = 0;
//         vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));

//         for (int i = 1; i <= A.size(); ++i) {
//             for (int j = 1; j <= B.size(); ++j) {
//                 if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
//                 ret = max(ret, dp[i][j]);
//             }
//         }
//         return ret;
//     }
// };
class Solution {
public:
    //! 滑动
    int maxLength(vector<int>& A, vector<int>& B, int addA, int addB, int len) {
        int ret = 0, k = 0;
        for (int i = 0; i < len; i++) {
            if (A[addA + i] == B[addB + i]) {
                k++;
            } else {
                k = 0;
            }
            ret = max(ret, k);
        }
        return ret;
    }
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        int ret = 0;
        for (int i = 0; i < n; i++) {
            int len = min(m, n - i);
            int maxlen = maxLength(A, B, i, 0, len);
            ret = max(ret, maxlen);
        }
        for (int i = 0; i < m; i++) {
            int len = min(n, m - i);
            int maxlen = maxLength(A, B, 0, i, len);
            ret = max(ret, maxlen);
        }
        return ret;
    }
};
// @lc code=end

