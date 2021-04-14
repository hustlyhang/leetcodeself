/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> bill(3, 0);
        int n = bills.size();
        for (int i = 0; i < n; ++i) {
            switch (bills[i])
            {   
            case 5:
                bill[0]++;
                break;
            case 10:
                if (bill[0] == 0) {
                    return false;
                }
                else {
                    bill[1]++;
                    bill[0]--;
                }
                break;
            case 20:
                if (bill[1] && bill[0]) {
                    bill[1]--;
                    bill[0]--;
                }
                else if (bill[0] >= 3) {
                    bill[0] -= 3;
                }
                else {
                    return false;
                }
                break;
            default:
                break;
            }
        }
        return true;
    }
};
// @lc code=end

