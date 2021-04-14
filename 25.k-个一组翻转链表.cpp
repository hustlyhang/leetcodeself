/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* headInsert(ListNode* p1, int k) {
        //cout<<"in"<<endl;
        ListNode* head = p1;
        ListNode* tmp = p1->next;
        ListNode* ret = p1->next;
        head->next = nullptr;
        ListNode *pos = tmp->next;
        int i = 0;
        while (i < k) {   
            tmp->next = head->next;
            head->next = tmp;
            tmp = pos;
            if (pos) pos = pos->next;
            //cout<< ret->val<<endl;
            i++;
        }
        
        return ret;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;
        // 头插法
        ListNode *HeadNull = new ListNode(0, head);
        int flg = 1;
        int nums = 0;
        ListNode* p1 = HeadNull;
        ListNode* p2 = HeadNull;
        while (flg) { 
            nums = 0;
            while(nums < k && p2 != nullptr) {
                p2 = p2->next;
                //cout<<p2->val<<endl;
                nums++;
            }
            if (p2 == nullptr) flg = 0;
            else {
                ListNode *h = p2->next;
                ListNode *n = headInsert(p1, k);
                n->next = h;
                p1 = n;
                p2 = n;
            }
        }
        return HeadNull->next;
    }
};
// @lc code=end

