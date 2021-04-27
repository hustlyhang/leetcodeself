/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n));
        int pos = 1;
        int i = 0, j = 0;
        // 计算出圈数
        int flg = n / 2;
        // cout<<flg<<endl;
        int tmp = 0; // 记录当前圈数
        while (tmp < flg)
        {
            for (i = tmp, j = tmp; j < n - tmp - 1; ++j)
                result[i][j] = pos++;
            // cout<<"左右"<<endl;
            for (; i < n - tmp - 1; ++i)
                result[i][j] = pos++;
            // cout<<"上下"<<endl;
            for (; j > tmp; --j)
                result[i][j] = pos++;
            // cout<<"右左"<<endl;
            for (; i > tmp; --i)
                result[i][j] = pos++;
            // cout<<"下上"<<endl;
            tmp++;
        }
        // 奇数的话特殊处理
        if (n % 2 == 1)
            result[n / 2][n / 2] = n * n;
        return result;
    }
};
// @lc code=end
