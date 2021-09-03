/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head, *pre = nullptr, *post = nullptr;
        if (cur == nullptr) return head;
        while (cur) {
            post = cur->next;
            cur->next = pre;
            pre = cur;
            cur = post;
        }
        return pre;
    }
};

// 翻转链表固定写法
/*
    三个指针，cur指向当前结点，post指向下一个结点，pre指向前一个结点
    刚开始时，pre为空，post为cur后一个结点。接下来进行迭代，每次更新cur的next
    指向，同时更新pre和post即可，最后返回pre
*/
// @lc code=end

