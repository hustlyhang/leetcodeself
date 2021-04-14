/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution1 {
public:
    bool isMatchCore(string s, string p, int i, int j) {
        //? 递归推出条件 如果任意一个字符串走到末尾，而另一个没有就不匹配

        if (s[i] == '\0' && p[j] == '\0') return true;
        if (p[j] == '\0') return false;

        //? 第一种情况 首先得判断特殊字符* 
        
        if (p[j + 1] == '*') {
            //? 因为可以匹配 0 以及 多个该字符 所以
            //? 先判断当前位置值是否相等
            if (p[j] == s[i] || (p[j] == '.' && s[i] != '\0')) {
                //! 因为和当前比较的不能是s的末尾
                //! 因为当s走到末尾时，还能和*进行匹配，但是却不能和.进行匹配，所以在
                //! 讨论.情况的时候需要排除s为\0的情况
                /*
                    * 如果当前值相等， 那么可以选择连续匹配 
                    * 当前值i往后移
                    * 或者只匹配一次 i后移， j后移两位
                    * 或者不匹配 j 后移两位
                */ 
               return isMatchCore(s, p, i + 1, j) || isMatchCore(s, p, i + 1, j + 2) || isMatchCore(s, p, i, j + 2);
            }
            else {
                //? 即当前两个值不匹配， 那么只能模式串向后移动，*不匹配
                return isMatchCore(s, p, i, j + 2);
            }
        }
        else if (p[j] == '.' && s[i] != '\0') {
            //! 因为和当前比较的不能是s的末尾
            return isMatchCore(s, p, i + 1, j + 1);
        }
        else if (s[i] == p[j]) return isMatchCore(s, p, i + 1, j + 1);
        else {
            return false;
        }
    }
    bool isMatch(string s, string p) {
        return(isMatchCore(s, p, 0, 0));
    }
};



//! 动态规划
class Solution {
public:
    bool isMatch(string s, string p) {
        s=" "+s;//防止该案例：""\n"c*"
        p=" "+p;
        int m=s.size(),n=p.size();
        bool dp[m+1][n+1];
        memset(dp,false,(m+1)*(n+1));
        dp[0][0]=true;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='.'){
                    //? 如果当前位置值相等，则匹配，那么以i，j结尾的字串匹配与否就取决与i-1，j-1结尾的字串是否匹配
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    //? 如果模式串遇到了'*' 那么
                    if(s[i-1]!=p[j-2] && p[j-2]!='.')
                        //? 如果字符串i位置和模式串前一个位置不匹配的话 就相当于当前的*不进行匹配，直接跳过
                        //? 那么以i，j结尾的字串匹配与否就取决与i，j-2结尾的字串是否匹配
                        dp[i][j]=dp[i][j-2];
                    else{
                        //? 如果字符串i位置和模式串前一个位置匹配的话 有三种情况
                        /*
                            * dp[i][j-1] 表示匹配一个
                            * dp[i][j-2] 表示匹配零个
                            * dp[i-1][j] 表示匹配n个， 因为s[i-1] == p[j-2] || p[j-2] == '.' ，
                            *   所以将i往前移，看前面还有能匹配p[j - 2] 的没有
                        */
                        dp[i][j]=dp[i][j-1] || dp[i][j-2] || dp[i-1][j];

                    }
                }
            }
        }
        return dp[m][n];
    }
};


class test{
public:
    bool isMatch(string s, string p) {
        int len1 = s.size(), len2 = p.size();
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        //?初始化
        dp[0][0] = true;
        for (int j = 1; j <= len2; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for(int i = 1; i < len1; ++i) {
            for(int j = 1; j < len2; ++j) {
                if (s[i - 1] == p[j - 1] || p[j  - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    //? 不匹配时
                    if (p[j - 1] == '*') {
                        if (s[i - 1] != p[j - 2] && p[j - 2] != '.') {
                            dp[i][j] = dp[i][j - 2];
                        }
                        else {
                            dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j];
                        }
                    }
                }
            }
        }
        return dp[len1][len2];
    }



};

// @lc code=end

