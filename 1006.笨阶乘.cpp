/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */

// @lc code=start
#include <stack>
#include <map>
using namespace std;

class Solution {
  public:
    stack<long> nums;
    stack<char> op;

    void cl() {
        long long a = nums.top();
        nums.pop();
        long long b = nums.top();
        nums.pop();
        char c = op.top();
        op.pop();
        switch (c) {
        case '*':
            nums.push(b * a);
            break;
        case '/':
            nums.push(b / a);
            break;
        case '+':
            nums.push(b + a);
            break;
        case '-':
            nums.push(b - a);
            break;
        default:
            break;
        }
    }
    int clumsy(int N) {
        map<char, int> pri = {
            {'*', 2},
            {'/', 2},
            {'+', 1},
            {'-', 1}
            };
        map<int, char> on = {
            {0, '*'},
            {1, '/'},
            {2, '+'},
            {3, '-'}
            };
        int j = 0;
        for (int i = N; i > 0; --i) {
            nums.push(i);
            if (i == 1) break;
            while (!op.empty() && pri[op.top()] >= pri[on[j%4]]) {
                cl();
            }
            op.push(on[j%4]);
            j++;
        }
        while (!op.empty()) {
            cl();
        }
        return nums.top();
    }
};
// @lc code=end
