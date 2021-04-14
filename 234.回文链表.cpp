/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start

// Definition for singly-linked list.
#include <stack>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    bool isPalindrome(ListNode *head) {
        ListNode* tmp = head;
        stack<int> s;
        int n = 0;
        while (tmp) {
            s.push(tmp->val);
            n++;
            tmp = tmp->next;
        }
        stack<int> t;
        bool flg = false;
        if (n % 2 == 0) flg = false;
        else flg = true;
        n /= 2;
        while (n--) {
            int d = s.top();
            s.pop();
            t.push(d);
        }
        if (flg) s.pop();
        // cout<<"s.size() = " << s.size()<<endl;
        // cout<<"t.size() = " << t.size()<<endl;

        bool ret = true;
        while (!s.empty() && !t.empty() && s.top() == t.top()) {
            s.pop();
            t.pop();
        }
        if (!s.empty() || !t.empty()) ret = false;
        return ret;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }

        // 找到前半部分链表的尾节点并反转后半部分链表
        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

        // 判断是否回文
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool result = true;
        while (result && p2 != nullptr) {
            if (p1->val != p2->val) {
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }        

        // 还原链表并返回结果
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

// @lc code=end
