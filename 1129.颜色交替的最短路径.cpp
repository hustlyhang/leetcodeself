/*
 * @lc app=leetcode.cn id=1129 lang=cpp
 *
 * [1129] 颜色交替的最短路径
 */

// @lc code=start
#include <vector>
#include <algorithm>
#define INF -99999
using namespace std;

class Solution {
  public:
    void dfs(vector<vector<vector<int>>> &g, int col, int i,
             vector<vector<int>> &res) {
        for (auto j : g[col][i]) {
            // i->j异色 距离更小
            if (res[i][col] + 1 < res[j][!col]) {
                res[j][!col] = res[i][col] + 1;
                dfs(g, !col, j, res);
            }
        }
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges,
                                         vector<vector<int>> &blue_edges) {
        // 首先生成邻接表
        vector<vector<int>> rg(n);
        vector<vector<int>> bg(n);
        for (auto c : red_edges) {
            rg[c[0]].push_back(c[1]);
        }
        for (auto c : blue_edges) {
            bg[c[0]].push_back(c[1]);
        }

        // 然后用一个
        vector<vector<vector<int>>> g{rg, bg};
        vector<vector<int>> res(n, {INF, INF});
        res[0] = {0, 0};

        // 开始两次DFS
        dfs(g, 0, 0, res);
        dfs(g, 1, 0, res);
        vector<int> out(n);
        for (int i = 0; i < n; ++i) {
            out[i] = min(res[i][0], res[i][1]);
            if (out[i] == INF)
                out[i] = -1;
        }
        return out;
    }
};
// @lc code=end
