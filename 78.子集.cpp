/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp;
    void subsetsCore(int i, vector<int> nums) {
        if (i == nums.size()) {
            ret.push_back(tmp);
            return;
        }
        else {
            // 是否选择这个数
            tmp.push_back(nums[i]);
            subsetsCore(i + 1, nums);
            tmp.pop_back();
            subsetsCore(i + 1, nums);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) return ret;
        subsetsCore(0, nums);
        return ret;
    }
};
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp;
    // 遍历完整个数组，每个可以选也可以不选，只有在遍历完整个数组后才能将临时数组加入到结果中

    void subsetsCore(int i, vector<int>& nums) {
        if (i == nums.size()) {
            ret.push_back(tmp);
            return;
        }    
        tmp.push_back(nums[i]);
        subsetsCore(i + 1, nums);
        tmp.pop_back();
        subsetsCore(i + 1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        subsetsCore(0, nums);
        return ret;
    }
};
// @lc code=end

