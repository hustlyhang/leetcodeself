/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start

//Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode* slow = head, *fast = head;
        do{
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
            else return false;
        }while(fast && fast != slow);
        return fast ? true : false;
    }
};
// @lc code=end

