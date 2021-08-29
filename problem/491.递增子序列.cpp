/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp;
    void findSubsequencesCore(int i, vector<int> nums) {
        if (tmp.size() > 1) {
            ret.push_back(tmp);
        }
        int used[201] = {0}; // 这里使用数组来进行去重操作，题目说数值范围[-100, 100]
        for (int j = i; j < nums.size(); j++) {
            if ((!tmp.empty() && nums[j] < tmp.back())
                    || used[nums[j] + 100] == 1) {
                    continue;
            }
            used[nums[j] + 100] = 1; // 记录这个元素在本层用过了，本层后面不能再用了
            tmp.push_back(nums[j]);
            findSubsequencesCore(j + 1, nums);
            tmp.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        findSubsequencesCore(0, nums);
        return ret;
    }
};
// @lc code=end

