/*
 * @lc app=leetcode.cn id=802 lang=cpp
 *
 * [802] 找到最终的安全状态
 */

// @lc code=start
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> outDegree(n, 0);
        vector<vector<int>> revGraph(n, vector<int>{});
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            outDegree[i] = graph[i].size();
            for (auto &end : graph[i]) {
                // 存储和end节点连接的节点
                revGraph[end].push_back(i);
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outDegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int f = q.front();
            ans.push_back(f);
            q.pop();
            for (auto start : revGraph[f]) {
                // 将与出度为零的节点连接的结点减去其出度，然后观察其是否出度为零
                outDegree[start]--;
                if (outDegree[start] == 0)
                    q.push(start);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
