/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> flg;
    int t = 0;
    int sum = 0;
    vector<int> nums;
    string ans;
    void dfs(int start) {
        if (start == flg.size()) {
            sum++;
            if (sum == t) {
                for (auto x : nums) {
                    ans += to_string(x);
                }
                return;
            }
        }
        for (int i = 0; i < flg.size(); ++i) {
            if (flg[i] && sum < t){
                nums.push_back(i + 1);
                flg[i] = false;
                dfs(start + 1);
                nums.pop_back();
                flg[i] = true;
            }
        }
    }
    
    string getPermutation(int n, int k) {
        flg.assign(n, true);
        t = k;
        dfs(0);
        return ans;
    }
};
// @lc code=end

