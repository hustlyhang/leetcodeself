/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */

// @lc code=start

//Definition for singly-linked list.
using namespace std;

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *HeadNull = new ListNode(99999);
        HeadNull->next = head;
        ListNode *pre = HeadNull;
        ListNode *cur = head;
        ListNode *ne = head;

        while (cur != nullptr)
        {
            //cur = cur->next;
            if (cur != nullptr && cur->next != nullptr && cur->val != cur->next->val)
            {
                pre = cur;
                cur = cur->next;
            }
            else if (cur != nullptr && cur->next != nullptr && cur->val == cur->next->val)
            {
                ne = cur->next;
                while (ne != nullptr && ne->val == cur->val)
                {
                    ne = ne->next;
                }
                pre->next = ne;
                cur = ne;
            }
            else
            {
                cur = cur->next;
            }
        }
        return HeadNull->next;
    }
};
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *HeadNull = new ListNode(99999);
        HeadNull->next = head;
        ListNode *cur = HeadNull;

        while (cur->next && cur->next->next)
        {
            if (cur->next->val == cur->next->next->val)
            {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x)
                {
                    cur->next = cur->next->next;
                }
            }
            else
            {
                cur = cur->next;
            }
        }
        return HeadNull->next;
    }
};
// @lc code=end
