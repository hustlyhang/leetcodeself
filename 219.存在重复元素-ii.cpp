/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
typedef long long ll;
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;
        for(int i = 0; i < nums.size(); ++i) {
            if (s.find(nums[i]) != s.end()) return true;
            else s.insert(nums[i]);
            if (s.size() > k) {
                s.erase(nums[i - k]);
            }
        }
        return false;
    }
};
// @lc code=end

