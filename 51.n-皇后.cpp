/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> flg; // 保存每个位置状态
    vector<vector<int>> ret;
    vector<int> tmp;
    bool isOK(int i, int j, int n){
        // 判断上下 以及倾斜方向上是否放了皇后
        int x = i, y = j;
        for (int x = 0; x < n; ++x) if(flg[x][j]) return false;
        // 左上
        x = i;
        y = j;
        while (x >= 0 && y >= 0) {
            if (flg[x][y]) return false;
            x--;
            y--;
        }
        // 右上
        x = i;
        y = j;
        while (x >= 0 && y < n) {
            if (flg[x][y]) return false;
            x--;
            y++;
        }
        return true;
    }
    void solveNQueensCore(int i, int n) {
        if (i == n) {
            ret.push_back(tmp);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (isOK(i, j, n)) {
                flg[i][j] = 1;
                tmp.push_back(j);
                solveNQueensCore(i + 1, n);
                flg[i][j] = 0;
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        flg.assign(n, vector<int>(n, 0));
        solveNQueensCore(0, n);
        // 结果转换
        vector<vector<string>> result;
        for (auto x : ret) {
            vector<string> rettmp;
            for (auto y : x) {
                string s;
                int pos = y;
                while (pos--) s.push_back('.');
                s.push_back('Q');
                pos = n - y - 1;
                while (pos--) s.push_back('.');
                rettmp.push_back(s);
            }
            result.push_back(rettmp);
        }
        return result;
    }
};
// @lc code=end

