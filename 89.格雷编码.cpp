/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <iostream>
#include <math.h>
using namespace std;

class Solution1
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> se;
        vector<bool> flg(pow(2, n), true);
        int tmp = 0;

        se.push_back(tmp);
        flg[0] = false;
        while (se.size() != pow(2, n))
        {
            // cout<<"tmp = "<<tmp<<endl;
            for (int i = n - 1; i >= 0; --i)
            {
                int as = pow(2, i);

                // int tt = tmp & as;
                // cout<<"as = "<<as<<endl;
                // cout<<"tmp & as = "<<(tmp & as)<<endl;
                // cout<<"tmp^as = "<<(tmp^as)<<endl;
                // cout<<"tmp|as = "<<(tmp|as)<<endl;

                if (((tmp & as) == as) && flg[tmp ^ as])
                {
                    //cout<<"比较位为1"<<endl;
                    tmp = tmp ^ as;
                    se.push_back(tmp);
                    flg[tmp] = false;
                    break;
                }
                else if (((tmp & as) == 0) && flg[tmp | as])
                {
                    //cout<<"比较位为0"<<endl;
                    tmp = tmp | as;
                    se.push_back(tmp);
                    flg[tmp] = false;
                    break;
                }
            }
        }
        return se;
    }
};

// https://leetcode-cn.com/problems/gray-code/solution/c5xing-dai-ma-xiang-xi-jie-xi-dui-xin-sh-xrkw/
class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> ans;
        int powN = 1 << n;
        for (int i = 0; i < powN; ++i)
            ans.push_back(i ^ i >> 1);
        return ans;
    }
};

// @lc code=end
