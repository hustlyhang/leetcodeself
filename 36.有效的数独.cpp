/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<vector<bool>> fst, sec, thr;
        int rows = board.size(), cols = board[0].size();
        // fst.assign(rows, vector<bool>(cols, false));
        // sec.assign(rows, vector<bool>(cols, false));
        // thr.assign(rows, vector<bool>(cols, false));
        vector<int> nums(10, 0);
        bool ans = true;
        //? 横着
        for (int i = 0; i < rows; ++i) {
            nums.assign(10, 0);
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] >= '0' && board[i][j] <= '9' &&
                    !nums[board[i][j] - '0']) {
                    nums[board[i][j] - '0'] = 1;
                } else if (board[i][j] >= '0' && board[i][j] <= '9' &&
                           nums[board[i][j] - '0'])
                    return false;
            }
        }
        for (int j = 0; j < cols; ++j) {
            nums.assign(10, 0);
            for (int i = 0; i < rows; ++i) {
                if (board[i][j] >= '0' && board[i][j] <= '9' &&
                    !nums[board[i][j] - '0']) {
                    nums[board[i][j] - '0'] = 1;
                } else if (board[i][j] >= '0' && board[i][j] <= '9' &&
                           nums[board[i][j] - '0'])
                    return false;
            }
        }
        for (int i = 0; i < rows; i += 3) {
            for (int j = 0; j < cols; j += 3) {
                nums.assign(10, 0);
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        if (board[i + x][j + y] >= '0' &&
                            board[i + x][j + y] <= '9' &&
                            !nums[board[i + x][j + y] - '0']) {
                            nums[board[i + x][j + y] - '0'] = 1;
                        } else if (board[i + x][j + y] >= '0' &&
                                   board[i + x][j + y] <= '9' &&
                                   nums[board[i + x][j + y] - '0'])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<vector<int>> fst(9, vector<int>(9, 0));
        vector<vector<int>> sec(9, vector<int>(9, 0));
        vector<vector<int>> thr(9, vector<int>(9, 0));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                else {
                    int val = board[i][j] - '1';
                    int box = (i / 3) * 3 + j / 3;
                    if (fst[i][val] == 0 && sec[j][val] == 0 &&
                        thr[box][val] == 0) {
                        fst[i][val] = 1;
                        sec[j][val] = 1;
                        thr[box][val] = 1;
                    } else
                        return false;
                }
            }
        }
        return true;
    }
};

// @lc code=end
