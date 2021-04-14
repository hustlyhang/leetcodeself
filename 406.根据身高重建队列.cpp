/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

// class Solution {
// public:
//     static bool cmp(vector<int> a, vector<int> b) {
//         if (a[1] == b[1]) return a[0] < b[0];
//         return a[1] < b[1];
//     }
//     vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//         int n = people.size();
//         sort(people.begin(), people.end(), cmp);
//         for (int i = 0; i < n; ++i) {
//             int count = 0;
//             for (int j = 0; j < i; ++j) {
//                 if (people[j][0] >= people[i][0]) {
//                     count++;
//                     if (count > people[i][1]) {
//                         for (int x = i; x > j; --x) {
//                             swap(people[x], people[x - 1]);
//                         }
//                         break;
//                     }
//                 }
//             }
//         }
//         return people;
//     }
// };
// 版本二
class Solution {
public:
    // 身高从大到小排（身高相同k小的站前面）
    static bool cmp(const vector<int> a, const vector<int> b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort (people.begin(), people.end(), cmp);
        list<vector<int>> que; // list底层是链表实现，插入效率比vector高的多
        for (int i = 0; i < people.size(); i++) {
            int position = people[i][1]; // 插入到下标为position的位置
            std::list<vector<int>>::iterator it = que.begin();
            while (position--) { // 寻找在插入位置
                it++; 
            }
            que.insert(it, people[i]); 
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};
// @lc code=end

