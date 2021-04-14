/*
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */

// @lc code=start

#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    int slidingPuzzle(vector<vector<int>> &board) {
        int m = 2, n = 3;
        string start = "";
        string target = "123450";
        // 将 2x3 的数组转化成字符串
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                start.push_back(board[i][j] + '0');
            }
        }

        // 记录一维字符串的相邻索引
        //? 例如0的邻居只有1和3
        vector<vector<int>> neighbor = {{1, 3}, {0, 4, 2}, {1, 5},
                                        {0, 4}, {3, 1, 5}, {4, 2}};

        /******* BFS 算法框架开始 *******/
        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);

        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front();
                q.pop();
                // 判断是否达到目标局面
                if (target == cur) {
                    return step;
                }
                // 找到数字 0 的索引
                int idx = 0;
                for (; cur[idx] != '0'; idx++)
                    ;
                // 将数字 0 和相邻的数字交换位置
                for (int adj : neighbor[idx]) {
                    string new_board = cur;
                    swap(new_board[adj], new_board[idx]);
                    // 防止走回头路
                    if (!visited.count(new_board)) {
                        q.push(new_board);
                        visited.insert(new_board);
                    }
                }
            }
            step++;
        }
        return -1;
        /******* BFS 算法框架结束 *******/
    }
};



/*
todo BFS 将局面转为 string 每次从0的位置开始扩展
*/
class pra{
public:
    int slidingPuzzle(vector<vector<int>> &board) {
        //? 首先将局面转为string对象
        string cur("");
        for (auto x : board) {
            for (auto n : x) {
                cur.push_back('0' + n);
            }
        }
        
        //? 然后需要一个正确答案
        string rht = "123450";

        
        //? 为了方便从0的位置向周围扩展，需要记录每个位置可以扩展的位置 其中每个值代表该下标位置可以和哪些位置进行互换
        vector<vector<int>> as{{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};

        //? 进行bfs
        //? 需要队列，还要一个set来辅助当前状态是否已经访问

        queue<string> q;
        unordered_set<string> visited;
        q.push(cur);
        visited.insert(cur);
        int ret = 0;

        while (!q.empty()) {
            //! 注意需要用一个临时变量存储队列大小
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                //? 对当前步数得到的状态进行检查，观察是正确状态，是就退出，不是就将未访问过的周围状态加入到队列中
                string tmp = q.front();
                q.pop();
                if (tmp == rht) {
                    return ret;
                }
                else {
                    //? 先找到当前状态0的位置
                    int zpos = 0;

                    //! 注意数字和字符
                    while (zpos < tmp.size() &&tmp[zpos] != '0') zpos++;
                    //? 从0的位置向周围扩增，同时步数加一
                    for (auto x : as[zpos]) {
                        //? 交换两个位置
                        string new_str = tmp;
                        swap(new_str[zpos], new_str[x]);
                        //? 交换后的状态是否已经访问过，没有就添加到队列中
                        if (visited.count(new_str) == 0) {
                            visited.insert(new_str);
                            q.push(new_str);
                        }
                    }
                }
            }
            ret++;
        }
        return -1;
    }



};
// @lc code=end
