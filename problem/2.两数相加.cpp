/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    void addListNode(ListNode* p1, ListNode* p2) {
        int flg = 0;
        ListNode* pre = p1;// 需要记录当前节点的前一个节点， 为了在扩增位置时添加下一位
        while (p1 && p2) {
            pre = p1;
            int n1 = p1->val;
            p1->val = (p1->val + p2->val + flg) % 10;
            flg = (n1 + p2->val + flg) / 10;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        while (p1) {
            pre = p1;
            int n2 = p1->val;
            p1->val = (p1->val + flg) % 10;
            flg = (n2 + flg) / 10;
            p1 = p1->next;
        }
        if (flg) {
            ListNode* tmp = new ListNode(flg);
            pre->next = tmp;
        }
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int num1 = 1;
        while (p1) {
            p1 = p1->next;
            num1++;
        }
        int num2 = 1;
        while (p2) {
            p2 = p2->next;
            num2++;
        }
        p1 = l1;
        p2 = l2;
        if (num2 <= num1) {
            addListNode(p1, p2);
            return l1;
        }
        else {
            addListNode(p2, p1);
            return l2;
        }
        return nullptr;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode* ret = new ListNode(0);
        ListNode* cur = ret;
        int carry = 0, sum = 0;
        while (l1 || l2) {
            sum = 0;
            sum += (l1 == nullptr ? 0 : l1->val);
            sum += (l2 == nullptr ? 0 : l2->val);
            
            cur->next = new ListNode(0);
            cur = cur->next;
            cur->val = (sum + carry) % 10;
            carry = (sum + carry) / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) {
            cur->next = new ListNode(0);
            cur = cur->next;
            cur->val = carry;
        }
        return ret->next;
    }
};
// @lc code=end
