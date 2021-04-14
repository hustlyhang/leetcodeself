/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
  public:
    int networkDelayTime(vector<vector<int>> &times, int n, int K) {
        vector<vector<int>> g(n + 1, vector<int>(n + 1, INT_MAX));
        for (auto &v : times) {
            g[v[0]][v[1]] = v[2];
        }
        // 用一个二维数组存储边的信息
        //! 一个数组用于存储节点是否访问过，另一个数组存储距离
        //! 因为n是从1开始的，所以分配空间时需要n+1
        vector<bool> vis(n + 1, false);
        vector<int> dist(n + 1, INT_MAX);

        dist[K] = 0;
        // 一共需要考虑n个节点
        for (int i = 1; i <= n; i++) {
            int t = -1, m = INT_MAX; // 记录最小距离的节点和最小距离
            for (int j = 1; j <= n; j++) // 找到当前没有遍历过的 最小的距离
            {
                if (vis[j] == false && dist[j] < m) {
                    t = j;
                    m = dist[j];
                }
            }
            if (t == -1) return -1;
            
            vis[t] = true;
            for (int j = 1; j <= n; j++) {
                // 访问和t连接的且未被访问的节点，更新距离
                if (vis[j] == false && g[t][j] != INT_MAX && dist[j] > dist[t] + g[t][j]) //路径压缩
                {
                    dist[j] = dist[t] + g[t][j];
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end
