/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 娆″彇鍙嶅悗鏈�澶у寲鐨勬暟缁勫拰
 */

// @lc code=start
class Solution {
static bool cmp(int a, int b) {
    return abs(a) > abs(b);
}
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp);       // 第一步
        for (int i = 0; i < A.size(); i++) { // 第二步
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        while (K--) A[A.size() - 1] *= -1;  // 第三步 
        int result = 0;
        for (int a : A) result += a;        // 第四步
        return result;
    }
};
// @lc code=end

