/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k) {
        if (board[i][j] != s[k]) {
            return false;
        } else if (k == s.length() - 1) {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (const auto& dir: directions) {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj]) {
                    bool flag = check(board, visited, newi, newj, s, k + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};
class test {
public:
    vector<vector<bool>> flg;
    vector<int> x{1,-1,0,0}, y{0,0,1,-1};
    bool dfs(vector<vector<char>>& board, int i, int j, int index, string& word) {
        if (board[i][j] != word[index]) return false;
        if (index == word.size() - 1) return true;
        for (int k = 0; k < 4; ++k) {
            int ti = i + x[k], tj = j + y[k];
            if (ti >= 0 && ti < board.size() && tj >= 0 && tj < board[0].size() && flg[ti][tj]) {
                flg[ti][tj] = false;
                if (dfs(board, ti, tj, index + 1, word)) return true;
                flg[ti][tj] = true;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        flg.assign(board.size(), vector<bool>(board[0].size(), true));
        for (int i = 0; i< board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0])
                {   flg[i][j] = false;
                    if (dfs(board, i, j, 0, word)) return true;
                    flg[i][j] = true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

