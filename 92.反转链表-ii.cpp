/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        
        ListNode* HeadNull = new ListNode(0, head);
        // 首先找到 待反转的前一个节点 然后开始反转
        ListNode* pre = HeadNull;
        ListNode* cur = nullptr;
        ListNode* post = nullptr;
        int num = right - left + 1;
        //cout<< "nums  = "<< num<<endl;
        left--;
        while (left--) {
            pre = pre->next;
            cout<< pre->val<<endl;
        }
        // 找到前节点 然后头插法后面的num个节点， 要保存最后一个节点的下一个节点
        cur = pre->next;
        ListNode* t = cur;
        post = cur->next;
        pre->next = nullptr;
        ListNode* tmp = nullptr;
        while (num--) {
            cur->next = pre->next;
            pre->next = cur;
            //cout<< pre->val<<endl;
            cur = post;
            if (post) post = post->next;
            if (num == 0) {
                tmp = cur;
            }
        }
        t->next = tmp;
        return HeadNull->next;
    }
    // if (left == right || head == nullptr || head->next == nullptr)
    //         return head;
    //     ListNode *H = new ListNode(-1);
    //     H->next = head;
    //     ListNode *pre = H;
    //     int i = 1;
    //     while (i < left)
    //     {
    //         pre = pre->next;
    //         ++i;
    //     }
    //     ListNode *now = pre->next;
    //     if (now->next == nullptr)
    //         return head;
    //     ListNode *pos = now->next;
    //     pre->next = nullptr;
    //     i = 0;
    //     ListNode *rear = nullptr;
    //     while (i <= right - left)
    //     {
    //         if (i == 0)
    //             rear = now;
    //         now->next = pre->next;
    //         pre->next = now;
    //         now = pos;
    //         if (now)
    //             pos = now->next;
    //         i++;
    //     }
    //     rear->next = now;
    //     return H->next;
    // }
};
// @lc code=end
