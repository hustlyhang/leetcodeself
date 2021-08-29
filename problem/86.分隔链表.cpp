/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

// @lc code=start

 // Definition for singly-linked list.
//   struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* H1 = new ListNode();
        ListNode* H2 = new ListNode();
        ListNode* cur1 = H1, *cur2 = H2;
        while (head) {
            ListNode* tmp = head;
            head = head->next;
            if (tmp->val < x) {
                cur1->next = tmp;
                cur1 = cur1->next;
                cur1->next = nullptr;
            }
            else {
                cur2->next = tmp;
                cur2 = cur2->next;
                cur2->next = nullptr;
            }
        }
        cur1->next = H2->next;
        return H1->next;
    }
};
// @lc code=end

