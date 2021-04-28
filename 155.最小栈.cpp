/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
    stack<long long> x_stack;
    long long mnum = 0;
public:
// 同时将当前元素和最小元素入栈
    MinStack() {
        
    }
    
    void push(int x) {
        if (x_stack.empty()) {
            x_stack.push(0);
            mnum = x;
        }
        else {
            long long cmpare = x - mnum;
            if (cmpare < 0) {
                mnum = x;
            }
            x_stack.push(cmpare);
        }
    }
    
    void pop() {
        long long tmp = x_stack.top();
        x_stack.pop();
        mnum = tmp > 0 ? mnum : mnum - tmp;

    }
    
    int top() {
        long long tmp = x_stack.top();
        long long prem = tmp > 0 ? mnum : mnum - tmp;
        return x_stack.top() + prem;
    }
    
    int getMin() {
        return mnum;
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

