/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;

class SolutionSelf {
public:
    unordered_map<int, char> m {
        {1, 'I'},
        {5, 'V'},
        {10, 'X'},
        {50, 'L'},
        {100, 'C'},
        {500, 'D'},
        {1000,  'M'}
    };
    string deal(int n) {
        string tmp;
        if (n < 4) {
            for (int i = 0; i < n; ++i) tmp.push_back('I');
        }
        else if (n == 4) {
            tmp.push_back('I');
            tmp.push_back('V');
        }
        else if (n < 9) {
            tmp.push_back('V');
            for (int i = 0; i < n - 5; ++i) {
                tmp.push_back('I');
            }
        }
        else if (n == 9) {
            tmp.push_back('I');
            tmp.push_back('X');
        }
        else if (n < 40) {
            for (int i = 0; i < n/10; ++i) tmp.push_back('X');
        }
        else if (n == 40) {
            tmp.push_back('X');
            tmp.push_back('L');
        }
        else if (n < 90) {
            tmp.push_back('L');
            for (int i = 0; i < n/10 - 5; ++i) {
                tmp.push_back('X');
            }
        }
        else if (n == 90) {
            tmp.push_back('X');
            tmp.push_back('C');
        }
        else if (n < 400) {
            for (int i = 0; i < n/100; ++i) tmp.push_back('C');
        }
        else if (n == 400) {
            tmp.push_back('C');
            tmp.push_back('D');
        }
        else if (n < 900) {
            tmp.push_back('D');
            for (int i = 0; i < n/100 - 5; ++i) {
                tmp.push_back('C');
            }
        }
        else if (n == 900) {
            tmp.push_back('C');
            tmp.push_back('M');
        }
        else {
            for (int i = 0; i < n/1000; ++i) {
                tmp.push_back('M');
            }
        }
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }
    string intToRoman(int num) {
        string ret;
        int flg = 0;
        while (num) {
            ret += deal(num%10 * pow(10, flg));
            num/=10;
            flg++;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};


class Solution {
public:
    string intToRoman(int num) {
        
        return intToRomanOneBit(num/1000, 'M', 0, 0)              // 千位
             + intToRomanOneBit((num%1000)/100, 'C', 'D', 'M') // 百位
             + intToRomanOneBit((num%100)/10, 'X', 'L', 'C')       // 十位
             + intToRomanOneBit(num%10, 'I', 'V', 'X');                // 个位
    }
private:
    string intToRomanOneBit(int num, char one, char five, char ten){
        if(num <=3){
            return string(num, one);
        }
        if(num == 4){
            return string("") + one + five;
        }
        if(num <= 8){
            return string("") + five + string(num-5, one);
        }
        return string("") + one + ten;
    }
};
// @lc code=end

