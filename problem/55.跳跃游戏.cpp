/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 璺宠穬娓告垙
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution1
{
public:
    bool canJump(vector<int> &nums)
    {
        int cover = 0;
        if (nums.size() == 1)
            return true; // 只有一个元素，就是能达到
        for (int i = 0; i <= cover; i++)
        { // 注意这里是小于等于cover
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1)
                return true; // 说明可以覆盖到终点了
        }
        return false;
    }
};

/*
    维持一个当前位置，下一个位置，以及在当前位置到下一位置可以到达
    最远的位置，每次走到下一位置，就更新下一位置到最远位置
*/
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int right = 0, next = 0;
        int cur = 0;
        while (cur < nums.size() && next < nums.size() - 1)
        {
            right = max(right, cur + nums[cur]);
            if (cur == next)
            {
                next = right;
            }
            cur++;
        }
        if (cur == nums.size())
            return false;
        return true;
    }
};
// @lc code=end
