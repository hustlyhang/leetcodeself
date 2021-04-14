/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start

//  Definition for singly-linked list.
#include <vector>
#include <algorithm>
using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// class Solution
// {
// public:
//     ListNode *mergeKLists(vector<ListNode *> &lists)
//     {
//         ListNode* ret = new ListNode(0);
//         ListNode* head = ret;
//         bool flg = true;
//         while (flg) 
//         {
//             int pos = 0;// 记录最大元素位置
//             int m = INT_MAX;
//             flg = false;
//             for (int i = 0; i < lists.size(); ++i) 
//             {
//                 if (lists[i] == nullptr) continue;
//                 //cout<< lists[i]->val<<endl;
//                 if (lists[i]->val <= m)
//                 {
//                     pos = i;
//                     m = lists[i]->val;
//                     flg = true;
//                 }
//             }
//             // 找到最小的那个位置
//             if (!flg) continue;
//             ListNode* tmp = new ListNode(lists[pos]->val);
//             lists[pos] = lists[pos]->next;
//             head->next = tmp;
//             head = head->next;
//         }
//         return ret->next;
//     }
// };
// 也可以用优先级队列来优化寻找过程
class Solution {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr; 
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};
// @lc code=end
