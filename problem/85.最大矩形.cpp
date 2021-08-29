/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class so {
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
class Solution {
public:
    so m;

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = 0;
        //cout<<rows<<' '<<cols;
        if (rows == 0) return 0;
        else cols = matrix[0].size();
        vector<vector<int>> nums(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (j == 0) {
                    nums[i][j] = matrix[i][j] - '0';
                    continue;
                }
                if (matrix[i][j] == '1') {
                    nums[i][j] = 1;
                    nums[i][j] += nums[i][j - 1];
                }
                else {
                    nums[i][j] = 0;
                }
            }
        }
        // for (int i = 0; i < rows; ++i) {
        //     for (int j = 0; j < cols; ++j) {
        //         cout<<nums[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans = 0;
        for (int j = 0; j < cols; ++j) {
            vector<int> tmp;
            for (int i = 0; i < rows; ++i) {
                tmp.push_back(nums[i][j]);
            }
            ans = max(ans,m.largestRectangleArea(tmp));
        }
        return ans;
    }
};
// @lc code=end

