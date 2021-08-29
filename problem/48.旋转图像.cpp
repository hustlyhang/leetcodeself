/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
  public:
    void rotate(vector<vector<int>> &matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        for (int i = 0; i < rows - 1; ++i) {
            for (int j = 0; j + i < rows - 1; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[rows - 1 - j][cols - 1 - i];
                matrix[rows - 1 - j][cols - 1 - i] = tmp;
            }
        }
        reverse(matrix.begin(), matrix.end());
    }
};
// @lc code=end
