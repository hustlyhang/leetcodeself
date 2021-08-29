/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */

// @lc code=start
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    typedef long long ll;
    
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> m;
        int ret = 0;
        for (int i = 0; i < wall.size(); ++i) {
            ll sum = 0;
            for (int j = 0; j < wall[i].size(); ++j){
                sum+=wall[i][j];
                if (m.find(sum) == m.end()) m[sum] = 1;
                else m[sum]++;
                if (m[sum] > ret && j != wall[i].size() - 1) {
                    ret = m[sum];
                    // cout<<"ret = "<<ret<<endl;
                    // cout<<"sum = "<<sum<<endl;

                }
            }
        }
        return wall.size() - ret;
    }
};
// @lc code=end

