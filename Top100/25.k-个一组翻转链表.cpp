/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start

// Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode* pre = nullptr, *post = nullptr, *cur = head;
        for (int i = 1; i < k; ++i) {
            cur = cur->next;
            if (cur == nullptr) return head;
        }
        cur = head;

        for (int i = 0; i < k; ++i) {
            post = cur->next;
            cur->next = pre;
            pre = cur;
            cur = post;
        }
        head->next = reverseKGroup(cur, k);
        return pre;
    }
};
// @lc code=end

