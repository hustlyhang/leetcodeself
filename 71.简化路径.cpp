/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
#include <string>
#include <deque>
using namespace std;


/*
    * 注意在加入到队列中的时候就需要将.和..剔除
*/
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> ch;
        bool ispath = false;

        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/') continue;
            else {
                string tmp;
                while (i < path.size() && path[i] != '/') {
                    tmp.push_back(path[i]);
                    i++;
                }
                i--;
                if (tmp == ".") {
                    continue;
                }
                if (tmp == "..") {
                    if (!ch.empty())
                        ch.pop_back();
                    continue;
                }
                ch.push_back(tmp);
            }
        }
        string ans;
        while (!ch.empty()) {
            auto str = ch.back();
            if (str == ".") {
                ch.pop_back();
            }
            else if (str == "..") {
                ch.pop_back();
                if (!ch.empty()) {
                    ch.pop_back();
                }
            }
            else {
                reverse(str.begin(), str.end());
                ans+=str;
                ans.push_back('/');
                ch.pop_back();
            }
        }
        if (ans.size() == 0) return "/";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

