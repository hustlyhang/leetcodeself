/*
 * @lc app=leetcode.cn id=1588 lang=cpp
 *
 * [1588] 所有奇数长度子数组的和
 */

// @lc code=start
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    // 前缀和
    int sumOddLengthSubarrays1(vector<int>& arr) {
        int len = arr.size();
        if (len == 1) return arr[0];
        vector<int> s(len + 1, 0);
        for (int i = 1; i <= len; ++i) {
            // 前缀和
            s[i] = s[i - 1] + arr[i - 1];
        }
        int ret = 0;
        for (int i = 1; i <= len; i += 2) {
            for (int j = i; j <= len; ++j) {
                ret += s[j] - s[j - i];
            }
        }
        return ret;
    }
    // 数学
    int sumOddLengthSubarrays(vector<int>& arr) {
        // 求每个位置的数字对奇数子序列的贡献
        int ret = 0;
        for (int i = 0; i < arr.size(); ++i) {
            int le = i / 2 + 1;
            int lo = (i + 1) / 2;
            int re = (arr.size() - i - 1) / 2 + 1;
            int ro = (arr.size() - i) / 2;
            ret += arr[i] * (le * re + lo * ro);
        }
        return ret;
    }
};
/*
1   4   2   5   3
1   1   1   1   1
1   1   1   1   1
    1   1   1   
        1

1   2   3   4   5   6
1   1   1   1   1   1
1   1   1   1   1   1
1   1   1   1   1   1
    1   1   1   1
    1   1   1   1
        1   1
*/

// @lc code=end

