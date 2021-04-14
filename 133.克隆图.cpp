/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start

// Definition for a Node.
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
  public:
    int val;
    vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
  private:
    unordered_map<Node *, Node *> mmp;

  public:
    Node *cloneGraph(Node *node) {
        if (node == nullptr)
            return nullptr;
        // 判断当前节点是否在mmp中,
        // 如果在的话直接返回就行，不在就要构建一个新节点，再放入mmp中. 因为可能会有重复的，为无向图
        if (mmp.count(node))
            return mmp[node];
        Node *tmp = new Node(node->val);
        mmp[node] = tmp; // 建立原节点与我们拷贝节点的联系
        for (auto &l : node->neighbors) {
            tmp->neighbors.push_back(cloneGraph(l));
        }
        return tmp;
    }
};
// @lc code=end
