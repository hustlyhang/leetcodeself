/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

struct Node{
    int val, i, j;
    Node(int _val, int _i, int _j):val(_val), i(_i), j(_j){};
};
struct cmp{
    bool operator()(Node &a, Node& b) {
        return a.val > b.val;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Node, vector<Node>, cmp> pq;
        for (int i = 0; i < matrix.size(); ++i) {
            pq.emplace(Node(matrix[i][0], i, 0));
        }
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            ans = pq.top().val;
            int posi = pq.top().i;
            int posj = pq.top().j;
            //cout<<"ans = "<<ans<<endl;
            pq.pop();
            if (posj + 1 < matrix.size()) {
                //cout<<posi<<','<<posj<<endl;
                pq.emplace(Node(matrix[posi][posj + 1], posi, posj + 1));
            }
        }
        return ans;

    }
};
// @lc code=end

