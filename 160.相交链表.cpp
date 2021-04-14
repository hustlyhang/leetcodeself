/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start

 //* Definition for singly-linked list.
#include <iostream>
using namespace std;

// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
//  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ta = headA;
        ListNode *tb = headB;
        bool flg1 = true, flg2 = true;
        while (ta != nullptr && tb != nullptr && ta != tb) {
            ta = ta->next;
            tb = tb->next;
            if (flg1 && ta == nullptr) {
                ta = headB;
                flg1 = false;
            }
            if (flg2 && tb == nullptr) {
                tb = headA;
                flg2 = false;
            }
        }
        if (ta == tb) return ta;
        else return nullptr;
    }
};
// @lc code=end

