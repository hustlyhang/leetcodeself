/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2) return s;

        int i = 0, j = 0;
        int len = s.size();
        //? 行数为numRows 列数为(1 + numRows - 2) * (len/(numRows + numRows - 2) + 1)
        int c = (1 + numRows - 2) * (len/(numRows + numRows - 2) + 1);
        vector<vector<char>> ch(numRows, vector<char>(c, ' '));


        for (auto c : s) {
            if (j % (numRows - 1) == 0) {
                ch[i++][j] = c;
                if (i == numRows) {
                    j++;
                    i--;
                    i--;
                }
            }
            else {
                //cout<<"i = "<<i<<endl;
                ch[i--][j++] = c;
            }
        }
        //cout<<"shuchu"<<endl;
        string ret;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < c; ++j) {
                if (ch[i][j] != ' ') ret.push_back(ch[i][j]);
            }
        }
        return ret;
    }
};
// @lc code=end

