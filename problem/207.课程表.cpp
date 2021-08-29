/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#include <queue>
#include <set>
#include <vector>
using namespace std;

// class Solution {
//   public:
//     bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
//         // 用什么结构存储便于删除和查
//         vector<set<int>> node(numCourses);
//         for (auto x : prerequisites) {
//             node[x[0]].insert(x[1]);
//         }
//         bool flg = true;
//         bool ret = false;
//         vector<int> tmp;
//         vector<bool> s(numCourses, true);
//         int m = 0;
//         while (flg) {
//             flg = false;
//             tmp.clear();
//             for (int i = 0; i < numCourses; ++i) {
//                 if (node[i].size() == 0 && s[i]) {
//                     tmp.push_back(i);
//                     s[i] = false;
//                     m++;
//                     // 说明有新的入度为零的节点
//                     flg = true;
//                 }
//             }
//             // 清除
//             for (auto &n : node) {
//                 for (auto x : tmp) {
//                     if (n.find(x) != n.end()) {
//                         n.erase(n.find(x));
//                     }
//                 }
//             }
//             if (m == numCourses) {
//                 flg = false;
//                 ret = true;
//             }
//         }
//         return ret;
//     }
// };
class Solution {
  public:
  // 利用一个数组存储入度为零的节点，然后用二维表存储每个点的出边，用一个队列维护入度为零的节点
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> graph(
            numCourses); //构建临接表（用vector储存临接点，方便访问）
        vector<int> v;
        for (int i = 0; i < numCourses; i++) {
            indegree[i] = 0;
            graph.push_back(v);
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            indegree[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].push_back(
                prerequisites[i][0]); //存的是出边
        }
        //将入度为0的顶点入队
        queue<int> myqueue;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                myqueue.push(i);
        }
        int cnt = 0;
        while (!myqueue.empty()) {
            int temp = myqueue.front();
            myqueue.pop();
            cnt++;
            //更新：
            for (int i = 0; i < graph[temp].size(); i++) {
                indegree[graph[temp][i]]--;
                if (indegree[graph[temp][i]] == 0) //放在这里做！只判断邻接点。
                    myqueue.push(graph[temp][i]);
            }
        }
        return cnt == numCourses;
    }
};

// @lc code=end
