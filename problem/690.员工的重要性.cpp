/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start

// Definition for Employee.
#include <vector>
#include <unordered_map>
using namespace std;

// class Employee
// {
// public:
//     int id;
//     int importance;
//     vector<int> subordinates;
// };

class Solution
{
public:
    int getSum(Employee *em, unordered_map<int, Employee *> &um)
    {
        if (em->subordinates.size() == 0)
            return em->importance;
        int ret = 0;
        for (auto x : em->subordinates)
        {
            ret += getSum(um[x], um);
        }
        return ret + em->importance;
    }
    int getImportance(vector<Employee *> employees, int id)
    {
        unordered_map<int, Employee *> um;
        for (auto x : employees)
        {
            um[x->id] = x;
        }
        return getSum(um[id], um);
    }
};
// @lc code=end
