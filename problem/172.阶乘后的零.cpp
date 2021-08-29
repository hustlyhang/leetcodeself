/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    //! 利用两个数组分别存储质因数和个数
    vector<int> pri;
    vector<int> sum;
    int index = 0;
    int ret = INT_MAX;

    //? 首先要 求出进制的质因数分解
    void split(long n) {
        for (int i = 2; i * i < n; ++i) {
            while (n % i == 0) {
                pri[index] = i;
                sum[index]++;
                n/=i;
            }
            index++;
        }
        //? 如果最后没有能除的话，就将其放入质因数数组中
        if (n > 1) {
            pri[index] = n;
            sum[index++]++;
        }
    }

    //? 然后 在阶乘的数中找到 质因数 的个数
    int findNum(int n, int sumX) {
        int ret = 0;
        while (n) {
            //? 因为总能在小于n的数中找到能整除sumX
            ret+=n/sumX;
            n/=sumX;
        }
        return ret;
    }

    int trailingZeroes(int n) {
        pri.assign(10001, 0);
        sum.assign(10001, 0);
        split(10);
        for (int i = 0; i < index; ++i) {
            ret = min(ret, findNum(n, pri[i])/sum[i]);
        }
        return ret;
    }
};
// @lc code=end

