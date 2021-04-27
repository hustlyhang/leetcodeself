/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
#include <vector>
using namespace std;

/*
    利用二分查找，查找最低载重
*/
class Solution {
public:
    int getDays(vector<int>& weights, int bags) {
        int ans = 0, sum = 0;
        int i = 0;
        while (i < weights.size()) {
            if (bags < weights[i]) return INT_MAX;
            sum += weights[i];
            if (sum > bags) {
                ans++;
                i--;
                sum = 0;
            }
            i++;
        }
        if (sum) ans++;
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int wSum = 0;
        for (auto x : weights) wSum+=x;
        int equ = wSum/D;
        int l = equ, r = wSum;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (getDays(weights, mid) > D) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return l;
        
    }
};
// @lc code=end

