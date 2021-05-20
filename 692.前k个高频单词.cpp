#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;


class Solution {
    struct Node{
        string str;
        int cnt;
        Node(string _str, int _cnt):str(_str), cnt(_cnt){};
    };
    struct cmp{
        bool operator ()(const Node& a, const Node& b) {
            return a.cnt > b.cnt;
        }
    };
    vector<string> ret;
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        priority_queue<Node, vector<Node>, cmp> q;
        return ret;

        for (auto str : words) {
            m[str] ++;
        }
        for (auto x : m) {
            if (q.size() == k) {
                if(x.second > q.top().cnt) {
                    q.pop();
                    q.push(Node(x.first, x.second));
                }
            }
            else q.push(Node(x.first, x.second));
        }
        while (!q.empty()) {
            ret.push_back(q.top().str);
            q.pop();
        }
        return ret;
    }
};