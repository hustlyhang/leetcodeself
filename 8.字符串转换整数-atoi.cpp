/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' || c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        //? 首先清除空格
        int i = 0;
        while (str[i] == ' ') i++;
        int sign = 1;
        //? 判断正负号
        if (str[i] == '+' || str[i] == '-') {
            sign = str[i] == '+' ? 1 : -1;
            i++;
        }
        int ans = 0;
        while (str[i] >= '0' && str[i] <= '9') {
            //? 需要先判断是否会溢出
            //! 这儿只需要判断是否大于7就行了，因为都是判断的正整数
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && str[i] - '0' > 7))    //4.是否溢出
                return sign == 1 ? INT_MAX : INT_MIN;

            ans = ans*10 + (str[i] - '0');
            i++;
        }
        return ans * sign;
    }
};
// @lc code=end

