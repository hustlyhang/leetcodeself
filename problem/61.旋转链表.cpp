/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start

//Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr) return head; 
        ListNode* tmp = head;
        int nums = 1;
        while (tmp->next) {
            nums++;
            tmp = tmp->next;
        }
        k = k % nums;
        nums -= k;
        tmp->next = head;
        ListNode* pos = head;
        ListNode* pre = head;
        while (nums--) {
            pre = pos;
            pos = pos->next;
        }
        pre->next = nullptr;
        return pos;
    }
};
// @lc code=end
