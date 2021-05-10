/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

/*
todo
每次将divisor翻倍，观察dividend是否大于它，大的话继续翻倍，否则将dividend减去翻倍后的数字
todo 重复这个过程
*/
class Solution1 {
  public:
    int divideCore(int dividend, int divisor) {
        //? 递归退出条件 dividend < divisor
        if (dividend < divisor)
            return 0;
        if (dividend == divisor)
            return 1;
        //? 如果dividend > divisor 的话 ，就循环
        int ret = 0;
        int tmp = divisor;
        while (dividend > tmp) {
            tmp <<= 1;
            // cout<<"tmp = "<<tmp<<endl;
            if (ret == 0)
                ret = 1;
            else {
                ret <<= 1;
            }
        }
        tmp >>= 1;
        return ret + divideCore(dividend - tmp, divisor);
    }

    int divide(int dividend, int divisor) {
        long ret = 0;
        bool flg = false;

        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            flg = true;
        if (abs(divisor) == 1)
            ret = abs(dividend);
        else {
            ret = divideCore(abs(dividend), abs(divisor));
        }
        if (ret > INT_MAX)
            ret = INT_MAX;
        return flg == true ? -ret : ret;
    }
};

// int main (){
//     Solution s;
//     cout<<"result="<<s.divideCore(10, 3);

//     return 0;
// }

class Solution {
  public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (divisor == -1) {
            if (dividend > INT_MIN)
                return -dividend; // 只要不是最小的那个整数，都是直接返回相反数就好啦
            return INT_MAX; // 是最小的那个，那就返回最大的整数啦
        }
        long a = dividend;
        long b = divisor;
        int sign = 1;
        if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
            sign = -1;
        }
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        long res = div(a, b);
        if (sign > 0)
            return res > INT_MAX ? INT_MAX : res;
        return -res;
    }
    // long div(long a, long b) { // 似乎精髓和难点就在于下面这几句
    //     if (a < b)
    //         return 0;
    //     long count = 1;
    //     long tb = b; // 在后面的代码中不更新b
    //     while ((tb + tb) <= a) {
    //         count = count + count; // 最小解翻倍
    //         tb = tb + tb;          // 当前测试的值也翻倍
    //     }
    //     return count + div(a - tb, b);
    // }

    long div(long a, long b) {
        if (a < b) return 0;
        long tb = b;
        long count = 1;
        while ((tb<<1) <= a) {
            count<<=1;
            tb<<=1;
        }
        return count + div(a - tb, b);
    }
};
// @lc code=end
