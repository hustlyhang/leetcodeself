/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int i, j, h;
    Node(int i, int j, int h) : i(i), j(j), h(h){};
    //? 重载小于符号, 因为默认优先队列为大顶堆，所以要重载小于符号，变为小根堆
    bool operator<(const Node &c) const { return h > c.h; }
};

class Solution {
  public:
    int trapRainWater(vector<vector<int>> &heightMap) {
        /*
        todo 首先需要一个数组来标识当前位置是否已经访问
        todo 需要一个队列存储已经访问的位置，相当于一个木桶，每次装水都取决于最短的那块
        todo 需要维持一个当前可以装水的最小高度 h
        */
        priority_queue<Node> p;
        int rows = heightMap.size();
        int cols = heightMap[0].size();
        vector<vector<bool>> isVisited(rows, vector<bool>(cols, false));
        int h = 0, ret = 0;

        //? 然后将周围一圈装到队列中去 并标记这些位置已经访问
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                    p.push(Node(i, j, heightMap[i][j]));
                    isVisited[i][j] = true;
                }
            }
        }

        //? 便于后面四周寻找
        vector<int> x{0, 0, -1, 1}, y{-1, 1, 0, 0};
        //? 然后开始将最低的那个地方弹出来进行扩展
        while (!p.empty()) {
            //?
            //比较当前的队列顶部和高度大小，如果比高度大的话，那么就要将高度增长，否则就可以装水
            Node tmp = p.top();
            if (h < tmp.h) {
                h++;
            } else {
                
                p.pop();

                //? 开始寻找四周有没有能装水的位置
                for (int k = 0; k < 4; ++k) {
                    int i = tmp.i + x[k], j = tmp.j + y[k];
                    if (i >=0 && i < rows && j >=0 && j < cols && isVisited[i][j] == false) {
                        //? 将这个位置标记为已访问，加入到队列中去
                        isVisited[i][j] = true;
                        if (heightMap[i][j] < h) ret += h - heightMap[i][j];
                        p.push(Node(i, j, heightMap[i][j]));
                    }
                }
            }
        }
        return ret;
    }
};

// struct Node {
//     int i, j, h;
//     Node(int ii, int jj, int hh) : i(ii), j(jj), h(hh) {}
//     bool operator<(const Node &root) const { return h > root.h; }
// };

class Solution1 {
  public:
    int trapRainWater(vector<vector<int>> &heightMap) {
        if (heightMap.size() == 0)
            return 0;
        int m = heightMap.size(), n = heightMap[0].size(), area = 0, h = 0;
        priority_queue<Node> q;
        vector<vector<bool>> visit(m, vector<bool>(n, false));

        //? 先将周围一圈加入到优先队列中
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    q.push(Node(i, j, heightMap[i][j]));
                    visit[i][j] = true;
                }
            }
        }
        //? 方便后面遍历周围一圈
        vector<int> x = {0, 0, -1, 1}, y = {-1, 1, 0, 0};
        while (!q.empty()) {
            auto f = q.top();

            /*
             * h代表当前周围栅栏的最低高度 所以当h小于队列首的高度时就将其增加
             * 而当队列首的高度小于其时，就要将其出队然后判断其能装多少水，且其周围的高度也
             * 比这低的话，还能继续装水
             */

            if (h < f.h)
                h++;
            else {
                q.pop();
                for (int k = 0; k < 4; k++) {
                    //? 遍历周围一圈，找到没有访问的边界
                    int i = f.i + x[k], j = f.j + y[k];
                    if (i >= 0 && i < m && j >= 0 && j < n &&
                        visit[i][j] == false) {
                        //?
                        //如果当前位置的高度比之前的水平面低的话，就加入到队列中去，然后找和其相连接的其他位置
                        int hh = heightMap[i][j];
                        if (hh < h)
                            area += h - hh;
                        q.push(Node(i, j, hh));
                        visit[i][j] = true;
                    }
                }
            }
        }
        return area;
    }
};

// @lc code=end
