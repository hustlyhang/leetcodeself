/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {

        ListNode *HeadNull = new ListNode(0, head);
        // 首先找到 待反转的前一个节点 然后开始反转
        ListNode *pre = nullptr;
        ListNode *cur = HeadNull;
        ListNode *post = nullptr;
        ListNode *tmp = HeadNull;
        int num = right - left + 1;
        for (int i = 0; i < left - 1; ++i)
        {
            cur = cur->next;
        }
        tmp = cur;
        cur = cur->next;
        ListNode *hh = cur;
        for (int i = 0; i <= right - left; ++i)
        {
            post = cur->next;
            cur->next = pre;
            pre = cur;
            cur = post;
        }

        hh->next = cur;
        tmp->next = pre;
        return HeadNull->next;
    }
};
// @lc code=end
