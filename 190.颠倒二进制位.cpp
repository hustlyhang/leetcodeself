/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
#include <stdint.h>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        uint32_t tmp = 0;
        uint32_t n_t = n;
        // 注意异或和位操作时要加等号，不然值不变
        int x = 32;
        while (x--) {
            tmp = n_t & 1;
            ret <<= 1;
            ret ^= tmp;
            n_t >>= 1;
            //cout << "i = " << n_t << endl;
        }
        return ret;
    }
};
// @lc code=end

