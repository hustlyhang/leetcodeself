/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution1 {
public:
    int sum[102][102] = {};
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size(), cols = matrix[0].size();

        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                for (int p = i; p <= rows; ++p) {
                    for (int q = j; q <= cols; ++q) {
                        if ((sum[p][q] - sum[p][j - 1] - sum[i - 1][q] + sum[i - 1][j - 1]) <= k) {
                            ans = max(ans, (sum[p][q] - sum[p][j - 1] - sum[i - 1][q] + sum[i - 1][j - 1]));
                        }
                        if (ans == k) return k;
                    }
                }
            }
        }
        return ans;
    }
};


/*
    * 二分
*/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> sum(rows + 1, vector<int>(cols + 1, 0));
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i <= rows; ++i) {
            for (int j = i; j <= rows; ++j) {
                set<int> s;
                s.insert(0);
                for (int l = 1; l <= cols; ++l) {
                    int right = sum[j][l] - sum[i - 1][l];
                    auto le = s.lower_bound(right - k);
                    if (le != s.end()) {
                        int cur = right - *le;
                        ans = max(ans, cur);
                        //if (ans == k) return ans;
                    }
                    s.insert(right);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

