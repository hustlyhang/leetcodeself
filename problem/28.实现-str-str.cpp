/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
  public:
    int *getNext(string p) {
        int *next = new int[p.length()];
        next[0] = -1; // while the first char not match, i++,j++
        int j = 0;
        int k = -1;
        while (j < (int)p.length() - 1) {
            if (k == -1 || p[j] == p[k]) {
                //? 相等的话就向后移
                j++;
                k++;
                next[j] = k;
            } else {
                //? 不相等的话就要往前找匹配位置，直到最前面
                k = next[k];
            }
        }
        return next;
    }

    int strStr(string haystack, string needle) {
        int i=0;
        int j=0;
        if (needle.size() == 0) return 0;
        int* next=getNext(needle);
        while (i < (int)haystack.length() && j < (int)needle.length())
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                j=next[j];
            }
        }
        if (j == (int)needle.length())
        {
            return i-j;
        }
        return -1;
    }
};


class test{

    int *getNext(string p){
        int len = p.size();
        int* next = new int[len];
        next[0] = -1;
        int k = -1, j = 0;
        while (j < len - 1) {
            if (k == -1 || p[k] == p[j]) {
                k++;
                j++;
                next[j] = k;
            }
            else {
                k = next[k];
            }
        }
        return next;
    }

    int strStr(string haystack, string needle) {
        int len1 = haystack.size(), len2 = needle.size();
        if (len2 == 0) return 0;
        int *next = getNext(needle);

        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                j = next[j];
            }
        }
        if (j == len2) return i - j;
        return -1;
    }   


};

class test{
    // 求next数组
    int *getNext(string needle) {
        int len = needle.size();
        int *next = new int[len];
        next[0] = -1;
        int k = -1, j = 0;
        while (j < len - 1) {
            if (k == -1 || needle[j] == needle[k]) {
                k++;
                j++;
                next[j] = k;
            }
            else {
                k = next[k];
            }
        }
        return next;
    }

    int strStr(string haystack, string needle) {
        int len1 = haystack.size(), len2 = needle.size();
        if (len2 == 0) return 0;
        int *next = getNext(needle);
        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                j = next[j];
            }
        }
        if (j == len2) return i - j;
        return -1;
    }


};
// @lc code=end
