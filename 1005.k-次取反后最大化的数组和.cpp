/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
static bool cmp(int a, int b) {
    return abs(a) > abs(b);
}
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp);       // ��һ��
        for (int i = 0; i < A.size(); i++) { // �ڶ���
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        while (K--) A[A.size() - 1] *= -1;  // ������ 
        int result = 0;
        for (int a : A) result += a;        // ���Ĳ�
        return result;
    }
};
// @lc code=end

