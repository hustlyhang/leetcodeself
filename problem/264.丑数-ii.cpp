/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start


/*
    todo 两种思路：都要考虑到丑数都是从2，3，5进行扩展的
    todo 第一种，利用有限队列来存储扩展得到的丑数，然后观察是否存在于队列中，利用一个set来去重
    todo 第二种， 动态规划？
*/

#include <queue>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;


class Solution1 {
public:
    int nthUglyNumber(int n) {
        long pos = 0, tmp = 0; //? pos记录当前为第几个丑数，tmp存储丑数
        vector<int> factor{2,3,5};
        priority_queue<long, vector<long>, greater<long>> q;
        q.push(1L);
        unordered_set<long> s;
        s.insert(1L);
        //pos++;
        while (pos != n) {
            tmp = q.top();
            q.pop();
            pos++;
            for (auto x : factor) {
                if (s.count(x * tmp) == 0) {
                    s.insert(x * tmp);
                    q.push(x * tmp);
                }
            }
        }
        return tmp;
    }
};

//! 动态规划

/*
  * dp[i] 表示第i个丑数，dp[1] = 1；
  * 同时维护三个指针 a, b, c 指向当前位置丑数通过 *2 *3 *5扩展来的位置选最小的那个，然后再更新a, b, c的值
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        int a = 1, b = 1, c = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = min({dp[a]*2, dp[b]*3, dp[c]*5});
            //dp[i] = min(min(dp[a]*2, dp[b]*3),dp[c]*5);

            //! 注意，可能有两个相等的，需要同时更新两个，所以不能else if
            if (dp[i] == dp[a]*2) a++;
            if (dp[i] == dp[b]*3) b++;
            if (dp[i] == dp[c]*5) c++;
        }
        return dp[n];
    }
};
// @lc code=end

