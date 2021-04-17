/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
#include <unordered_map>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    //? 记录操作符优先级
    unordered_map<char, int> mop{
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
    };
    stack<int> nums;
    stack<char> op;
    int calculate(string s) {
        int len = s.size();
        int i = 0, tmp = 0;

        //! 一开始就需要判断数字是否为负数，为了避免进行判断，可以先在栈中放一个0
        nums.push(0);
        while (i < len) {
            if (s[i] == ' ') {
                i++;
                continue;
                
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                while (i < len && s[i] >= '0' && s[i] <= '9') {
                    tmp*=10;
                    tmp+=s[i] - '0';
                    i++;
                }
                nums.push(tmp);
                tmp = 0;
            }
            else if (s[i] == '(') {
                //! 这儿需要注意 如果有负数的话，所以需要进行判断
                op.push(s[i]);
                i++;
                if (i < len - 1 && s[i + 1] == '-') {
                    nums.push(0);
                    op.push('-');
                    i++;
                }
            }
            else if (s[i] == ')') {
                //? 需要开始计算
                while (op.top() != '(') {
                    cal();
                }
                op.pop();
                i++;
            }
            else{
                while (!op.empty() && op.top()!='(' && mop[s[i]] <= mop[op.top()]) {
                    cal();
                }
                op.push(s[i]);
                i++;
            }
        }

        //! 这儿加（是因为防止计算式一开始就有括号
        while (!op.empty() && op.top() != '(') {
            cal();
        }
        return nums.top();
    }

    //? 计算函数
    void cal(){
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        char p = op.top();
        op.pop();
        if (p == '+') nums.push(a + b);
        else if (p == '-') nums.push(a - b);
        else if (p == '*') nums.push(a * b);
        else if (p == '/') nums.push(a / b);
    }
};


int main() {


    Solution ss;
    string s(" 3/2 ");
    ss.calculate(s);


    return 0;
}
// @lc code=end

