/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    int ks = 0, ns = 0;
    void dfs(int start) {
        if (tmp.size() == ks){
            ans.push_back(tmp);
            return;
        }

        for (int i = start; i <= ns; ++i) {
            tmp.push_back(i);
            dfs(i + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        ns = n;
        ks = k;
        dfs(1);
        return ans;
    }
};
// @lc code=end

