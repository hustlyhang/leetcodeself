/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    maxans = max(maxans, i - stk.top());
                }
            }
        }
        return maxans;
    }
};

class test{
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        //! st用来存放下标
        int m = 0;
        st.push(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                }
                else {
                    m = max(m, i - st.top());
                }
            }
        }
        return m;

    }
};
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if (len <= 1) return 0;
        int m = 0;
        vector<int> dp(len, 0);
        dp[0] = 0;
        for (int i = 1; i < len; ++i) {
            if (s[i] == '(') dp[i] = 0;
            else {
                //! 注意下标越界的情况
                if (s[i - 1] == '(') dp[i] = i-2 >=0 ? dp[i - 2] + 2 : 2;
                else {
                    //! 注意下标越界的情况
                    if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(' )  
                        dp[i] = i - dp[i - 1] - 2 >=0 ? dp[i - 1] + 2 + dp[i - dp[i - 1] - 2] : dp[i - 1] + 2;
                    else {
                        dp[i] = 0;
                    }
                }
            }
            m = max(m, dp[i]);
        }
        return m;
    }
};
// @lc code=end

