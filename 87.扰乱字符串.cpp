/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
#include <string>
using namespace std;

// class Solution {
// public:
//     bool isScramble(string s1, string s2) {
        
//     }
// };




//todo 递归思路
class Solution1 {
public:

    bool isScramble(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(m != n)
            return false;
        if(s1 == s2)
            return true;
        string s3 = s1;
        sort(s3.begin(), s3.end());
        string s4 = s2;
        sort(s4.begin(), s4.end());
        if(s3 != s4)
            return false;
        for(int i = 1; i < n; i++)
        {
            string x1 = s1.substr(0, i);
            string y1 = s1.substr(i, n-i);
            string x2 = s2.substr(0, i);
            string y2 = s2.substr(i, n-i);
            string x3 = s2.substr(0, n-i);
            string y3 = s2.substr(n-i,i);
            if(isScramble(x1,x2) && isScramble(y1,y2))
                return true;
            if(isScramble(y1,x3) && isScramble(x1,y3))
                return true;
        }
        return false;
    }
};

//todo 动态规划
class Solution{
public: bool isScramble(string s1, string s2){
        int n = s1.length();
        if (s2.length() != n) return false;
        bool ***dp = new bool **[n];
        for (int i = 0; i < n; i++){
            dp[i] = new bool *[n];
            for (int j = 0; j < n; j++){
                dp[i][j] = new bool[n + 1]();
                // 初始化单个字符的情况
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }
        // 枚举区间长度 2～n
        for (int len = 2; len <= n; len++){
            // 枚举 S 中的起点位置
            for (int i = 0; i <= n - len; i++){
                // 枚举 T 中的起点位置
                for (int j = 0; j <= n - len; j++){
                    // 枚举划分位置
                    for (int k = 1; k <= len - 1; k++){
                        // 第一种情况：S1 -> T1, S2 -> T2
                        if (dp[i][j][k] && dp[i + k][j + k][len - k]){
                            dp[i][j][len] = true; break;
                        }
                        // 第二种情况：S1 -> T2, S2 -> T1
                        if (dp[i][j + len - k][k] && dp[i + k][j][len - k]){
                            dp[i][j][len] = true; break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};


class test{
public:
    bool isScramble(string s1, string s2){
        //? 初始化dp数组
        int len = s1.size();
        if (s2.size() != len) return false;

        bool ***dp = new bool** [len];
        for (int i = 0; i < len; ++i) {
            dp[i] = new bool* [len];
            for (int j = 0; j < len; ++j) {
                dp[i][j] = new bool[len + 1]();
                //? 初始化
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }



        //? 考虑子字符串长度下是否匹配

        //? 长度需要从2开始，长度为1的时候已经初始化了

        for (int k = 2; k <= len; ++k) {
            //? 注意是等号
            for (int i = 0; i <= len - k; ++i) {
                for (int j = 0; j <= len - k; ++j) {
                    for (int l = 1; l <= k - 1; ++l) {
                        //? 正序匹配
                        if (dp[i][j][l] && dp[i + l][j + l][k - l]) {dp[i][j][k] = true;break;}
                        //? 交换匹配
                        if (dp[i][j + (k - l)][l] && dp[i + l][j][k - l]) {dp[i][j][k] = true; break;}                       
                    }

                }
            }
        }
        return dp[0][0][len];


    }


};
// @lc code=end

