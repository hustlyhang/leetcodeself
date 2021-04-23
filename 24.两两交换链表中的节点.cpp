/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
  public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *H = new ListNode(0, head);
        ListNode *tmp = head;
        ListNode *pre = H;
        while (tmp && tmp->next) {
            // ListNode* next = tmp->next->next;
            pre->next = tmp->next;
            tmp->next = pre->next->next;
            pre->next->next = tmp;
            tmp = tmp->next;
            pre = pre->next->next;
        }
        return H->next;
    }
};
// @lc code=end
