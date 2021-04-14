/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while (left <= right && top <= bottom) {
            int i = top;
            int j = left;
            for (; j <= right; ++j) {
                ret.push_back(matrix[top][j]);
            }
            for (i = top + 1; i <= bottom; ++i) {
                ret.push_back(matrix[i][right]);
            }
            if (top < bottom && left < right) {
                for (j = right - 1; j >= left; --j) {
                    ret.push_back(matrix[bottom][j]);
                }
                for (i = bottom - 1; i > top; --i) {
                    ret.push_back(matrix[i][left]);
                }
            }
            top++;
            left++;
            bottom--;
            right--;
        }
        return ret;
    }
};
// @lc code=end

