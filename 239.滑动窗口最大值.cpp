/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <set>
#include <vector>
using namespace std;

class Solution {
  private:
    class Myqueue {
      public:
        //实现push，pop，front功能
        deque<int> qu;
        // push
        //单调栈，在push时直到要进队列的值小于队列中的值时才进队

        void push(int i) {
            while (!qu.empty() && qu.back() < i)
                qu.pop_back();
            qu.push_back(i);
        }
        // pop操作
        //当待出队的值等于队头值时出队，否则不执行
        void pop(int i) {
            if (!qu.empty() && qu.front() == i)
                qu.pop_front();
        }
        //获取队首元素
        int front() { return qu.front(); }
    };

  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        Myqueue qu;
        vector<int> result;
        //首先将k个元素入队列
        for (int i = 0; i < n; ++i) {
            if (i < k - 1) {
                qu.push(nums[i]);
                continue;
            }
            qu.push(nums[i]);
            if (i > k - 1)
                qu.pop(nums[i - k]);
            result.push_back(qu.front());
        }
        return result;
    }
};
// @lc code=end
