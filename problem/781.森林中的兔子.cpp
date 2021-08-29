/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int len = answers.size();
        if (len == 0) return 0;
        sort(answers.begin(), answers.end());
        int ret = len;
        for (int i = 0; i < len; ++i) {
            if (answers[i] == 0) continue;
            int j = i;
            while (j < len && answers[j] == answers[i] && answers[i] >= j - i) {
                j++;
            }
            j--;
            // !需要考虑当一只兔子说的不满足时，即当answers[i]<(j - i)
            // cout<<"i = " << i <<endl;
            // cout<<"j - i = " << j - i <<endl;
            ret += answers[i] - (j - i);
            i = j;
        }
        return ret;
    }
};
// @lc code=end

