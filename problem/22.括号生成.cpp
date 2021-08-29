/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<string> ret;
    int i = 0;
    int pos = 0;
    string tmp;
    /*
     * 相当于每个位置可以放置
     * '('和')'但是放置')'需要检查前面是不是有相对应这么多个'('
     */
    void generateParenthesisCore(int n) {
        if (i == n) {
            int t = pos;
            while (t--)
                tmp.push_back(')');
            ret.push_back(tmp);
            t = pos;
            while (t--)
                tmp.pop_back();
            return;
        }
        tmp.push_back('(');
        i++;
        pos++;
        generateParenthesisCore(n);
        i--;
        pos--;
        tmp.pop_back();
        if (pos) {
            tmp.push_back(')');
            pos--;
            generateParenthesisCore(n);
            pos++;
            tmp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        generateParenthesisCore(n);
        return ret;
    }
};
// @lc code=end
