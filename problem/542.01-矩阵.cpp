/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    struct Node{
        int i,j;
        Node(int _i, int _j):i(_i),j(_j){};
    };
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<bool>> flg(rows, vector<bool>(cols, true));
        queue<Node> q;
        int t = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    q.push(Node(i, j));
                    t++;
                    flg[i][j] = false;
                }
            }
        }

        int path = 0;
        int tmp = 0;
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        vector<int> x{0,0,-1,1}, y{-1, 1, 0, 0};
        while (!q.empty()) {
            for (int i = 0; i < t; ++i) {
                auto no = q.front();
                q.pop();
                ans[no.i][no.j] = path;
                for (int k = 0; k < 4; ++k) {
                    int ti = no.i + x[k], tj = no.j + y[k];
                    if (ti < rows && ti >= 0 && tj < cols && tj >= 0 && flg[ti][tj]) {
                        q.push(Node(ti, tj));
                        flg[ti][tj] = false;
                        tmp++;
                    } 
                }
            }
            t = tmp;
            tmp = 0;
            path++;
        }
        return ans;
    }
};
// @lc code=end

