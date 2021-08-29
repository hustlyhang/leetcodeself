/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        reverse(s.begin(), s.end());
        int ans = 0;
        int pos = 0;
        while (pos < s.size() && s[pos] == ' ')
        {
            pos++;
        }

        if (pos == s.size())
            return ans;
        for (int i = pos; i < s.size(); ++i)
        {
            if (s[i] == ' ')
                break;
            else
                ans++;
        }
        return ans;
    }
};
// @lc code=end
