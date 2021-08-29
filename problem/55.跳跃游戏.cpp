/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
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
            return true; // ֻ��һ��Ԫ�أ������ܴﵽ
        for (int i = 0; i <= cover; i++)
        { // ע��������С�ڵ���cover
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1)
                return true; // ˵�����Ը��ǵ��յ���
        }
        return false;
    }
};

/*
    ά��һ����ǰλ�ã���һ��λ�ã��Լ��ڵ�ǰλ�õ���һλ�ÿ��Ե���
    ��Զ��λ�ã�ÿ���ߵ���һλ�ã��͸�����һλ�õ���Զλ��
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
