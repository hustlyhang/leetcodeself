/*
 * @lc app=leetcode.cn id=1707 lang=cpp
 *
 * [1707] 与数组中元素的最大异或值
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 * 31;
int son[N][2], idx;

class Solution {
public:
    static bool cmp(const vector<int>&a, const vector<int>&b){
        return a[1] <= b[1];
    }
    void insert(int x){
        int p = 0;
        for (int i = 30; ~i; --i) {
            int u = x>>i&1;
            if (!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
    }
    int query(int x){
        int ret = 0, p = 0;
        for (int i = 30; ~i; --i) {
            int u = x>>i&1;
            if (son[p][!u]) {
                ret<<=1;
                ret+=1;
                p = son[p][!u];
            }
            else {
                ret<<=1;
                p = son[p][u];
            }
        }
        return ret;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= queries.size(); ++i) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), cmp);
        vector<int> ret;
        return ret;
    }
};
// @lc code=end

