/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution1
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int l = 0; // 记录位移位数
        int len = nums.size();
        if (len <= 2)
            return len;
        int tmp = 10001;  // 记录上一个值
        bool flg = false; // 记录当前是否更新l
        for (int i = 0; i < len; ++i)
        {
            // 如果当前值等于上一记录且flg为真，那么就更新l
            if (nums[i] == tmp && flg)
            {
                l++;
            }
            else if (nums[i] == tmp && !flg)
            {
                flg = true;
            }
            else
            {
                tmp = nums[i];
                flg = false;
            }
            nums[i - l] = nums[i];
        }
        return len - l;
    }
};
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int len = nums.size();
        if (len <= 2)
            return len;
        int slow = 2, fast = 2;
        while (fast < len)
        {
            if (nums[fast] != nums[slow - 2])
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};
// @lc code=end
