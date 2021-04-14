/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr || l2 == nullptr) {
            return l1 == nullptr ? l2 : l1;
        }

        ListNode* tmp = l1->val <= l2->val ? l1 : l2;
        tmp->next = mergeTwoLists(tmp->next, tmp == l1 ? l2 : l1);
        return tmp;
    }
};
// @lc code=end
