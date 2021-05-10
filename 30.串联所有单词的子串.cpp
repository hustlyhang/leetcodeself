/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
todo 先将所有单词保存在字典中，key为单词，出现次数为value
todo 同时以每个字母为key 以该字母为首字母的单词为valu
*/

class Solution {
  public:
    vector<int> findSubstring(string s, vector<string> &words) {
        if (words.empty())
            return {};
        unordered_map<string, int> wordmap, smap;
        for (string word : words)
            wordmap[word]++;

        int wordlen = words[0].size();
        int wordnum = words.size();

        vector<int> ans;

        for (int k = 0; k < wordlen; k++) {
            int i = k, j = k;
            while (i < s.size() - wordnum * wordlen + 1) {
                while (j < i + wordnum * wordlen) {
                    string temp = s.substr(j, wordlen);
                    smap[temp]++;
                    j += wordlen;
                    if (wordmap[temp] == 0) { //情况二，有words中不存在的单词
                        i = j;                //对i加速
                        smap.clear();
                        break;
                    } else if (smap[temp] >
                               wordmap[temp]) { //情况三，子串中temp数量超了
                        while (smap[temp] > wordmap[temp]) {
                            smap[s.substr(i, wordlen)]--;
                            i += wordlen; //对i加速
                        }
                        break;
                    }
                }
                //正确匹配，由于情况二和三都对i加速了，不可能满足此条件
                if (j == i + wordlen * wordnum) {
                    ans.push_back(i);
                    smap[s.substr(i, wordlen)]--;
                    i += wordlen; // i正常前进
                }
            }
            smap.clear();
        }
        return ans;
    }
};

class pra{
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        if (words.empty())
            return {};
        //? 首先统计每个单词出现的次数
        unordered_map<string, int> times;
        for (auto x : words) {
            times[x]++;
        }
        //? 需要记录当前单词数组中每个单词的长度和单词个数
        int wt = words.size();
        int wl = words[0].size();

        vector<int> ret;

        unordered_map<string, int> as;

        //? 因为是一个一个单词进行匹配，所以从一个单词里面每个字母出发进行匹配
        for (int i = 0; i < wl; ++i) {
            //? 初始化左右边界

            int left = i, right = i;

            //? 相当于右边界进行移动，当不满足时，根据情况对左边界进行移动
            //? 同时需要另外一个map进行存储当前左右边界内含有的单词数目

            

            //? 剩余长度得大于单词里面总长度

            while (left < s.size() - wt * wl + 1) {
                //? 匹配长度不能超过总长度
                //! 注意循环退出条件 因为每一次都是加得wl所以是小于而不是小于等于
                while (right - left < wt * wl) {
                    //? 将单词添加到as中，然后再将as和times进行比较
                    string stmp = s.substr(right, wl);
                    right += wl;
                    //! 这儿必须将stmp加入到as中，因为相当于向后面匹配
                    as[stmp]++;
                    //? 如果times中找不到这个单词，就将左边界更新到右边界，同时清空as，相当于得重新匹配
                    if (times.count(stmp) == 0) {
                        left = right;
                        as.clear();
                        break;
                    }
                    else if (as[stmp] > times[stmp]){
                        //? 如果times中有这个单词， 添加到as中，然后观察这个单词是否多了
                        while (as[stmp] > times[stmp]) {
                            as[s.substr(left, wl)]--;
                            left += wl;
                        }
                        break;
                    }
                }

                //? 当退出循环说明 匹配成功，需要将left更新下一个单词,更新as数组

                //! 注意循环退出条件 因为每一次都是加得wl所以是小于而不是小于等于
                if (right - left == wt * wl) {
                    ret.push_back(left);
                    as[s.substr(left, wl)]--;
                    left += wl;
                }
            }
            //? 当前位置 匹配完成，需要清空as
            as.clear();
            //? 匹配结束
        }
        return ret;
    }
};

class test{
  public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> ret;
        int len = words.size();
        if (len == 0) return ret; 
        int wl = words[0].size();
        
        // 利用一个map记录所有的单词出现次数
        unordered_map<string, int> all;
        for (auto x : words) all[x]++;

        // 然后还有一个map记录当前的出现次数
        unordered_map<string, int> cur;
        
        // 为了减少分析情况，只需要从一个单词的长度开始分析即可
        for (int i = 0; i < wl; ++i) {
            // 然后开始往后分析
            // 将当前单词添加到临时map中
            int begin = i, end = i;
            cur.clear();
            while (begin + wl * len <= s.size()) {
                string nowWord = s.substr(end, wl);

                cur[nowWord] ++;
                end+=wl;
                if (all.count(nowWord) == 0) {
                    cur.clear();
                    begin = end;
                }
                else {
                    if (cur[nowWord] > all[nowWord]) {
                        while (cur[nowWord] > all[nowWord]) {
                            cur[s.substr(begin, wl)]--;
                            begin += wl;
                        }
                    }
                }
                if (end - begin == wl * len) {
                    ret.push_back(begin);
                    cur.clear();
                    begin+=wl;
                    end = begin;
                }
            }
             
        }
        return ret;
    }

};
// @lc code=end
