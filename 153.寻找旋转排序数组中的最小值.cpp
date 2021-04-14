/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小�?
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            //! ����ֵ����ֵ��ʱ����Ҫ�����ƣ��Ⱥŵ�Ŀ����Ϊ�˵�ֻ����������ʱ���Ը���l
            if (nums[m] >= nums[0]) {
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        //cout<<l<<endl;
        if (l == nums.size()) return nums[0];
        return nums[l];
    }
};
// @lc code=end

