/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // int result = INT32_MIN;
        // int count = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     count += nums[i];
        //     if (count > result) { // ȡ�����ۼƵ����ֵ���൱�ڲ���ȷ�����������ֹλ�ã�
        //         result = count;
        //     }
        //     if (count <= 0) count = 0; // �൱���������������ʼλ�ã���Ϊ��������һ���������ܺ�
        // }
        // return result;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp(n + 1, 0);
        int ret = INT_MIN;

        for (int i = 1; i <= n; ++i)
        {
            if (dp[i - 1] >= 0)
                dp[i] = dp[i - 1] + nums[i - 1];
            else
            {
                dp[i] = nums[i - 1];
            }
            ret = max(dp[i], ret);
        }
        return ret;
    }
};
// @lc code=end
