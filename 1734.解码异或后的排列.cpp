/*
 * @lc app=leetcode.cn id=1734 lang=cpp
 *
 * [1734] 解码异或后的排列
 */

// @lc code=start
#include <vector>
using namespace std;

// https://leetcode-cn.com/problems/decode-xored-permutation/solution/ji-shuang-yi-wen-dai-ni-shua-liang-dao-j-mujs/
class Solution {
public:
    // 需要求出第一个数字是多少，首先知道1-n所有元素的异或值，然后求出除第一个元素后所有元素的异或值，再异或一次就得出第一个元素的值
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        int total = 0;
        for (int i = 1; i <= n; i++) {
            total ^= i;
        }
        int odd = 0;
        for (int i = 1; i < n - 1; i += 2) {
            odd ^= encoded[i];
        }
        vector<int> perm(n);
        perm[0] = total ^ odd;
        for (int i = 0; i < n - 1; i++) {
            perm[i + 1] = perm[i] ^ encoded[i];
        }
        return perm;
    }
};
// @lc code=end
