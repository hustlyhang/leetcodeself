/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        vector<int> tmp;
        tmp.push_back(0);
        for (auto x : heights) tmp.push_back(x);
        int ans = 0;
        for (int i = 0; i < tmp.size(); ++i) {
            if (st.empty()) {
                st.push(i);
                continue;
            }
            if (tmp[i] < tmp[st.top()]) {
                while (tmp[i] < tmp[st.top()]) {
                    int pos = st.top();
                    st.pop();
                    ans = max(ans, (i - st.top() - 1) * tmp[pos]);
                }
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

