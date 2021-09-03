/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
#include <map>
using namespace std;

struct SNode {
    int key, value;
    SNode *pre, *post;
    SNode(int _key, int _value) : key(_key), value(_value), pre(nullptr), post(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        m_iCapcity = capacity;
        m_iCurNodeCnt = 0;
        m_pHead = new SNode(-1, -1);
        m_pRear = new SNode(-1, -1);
        m_pHead->post = m_pRear;
        m_pRear->pre = m_pHead;
    }
    
    int get(int key) {
        if (m_mKey2Node.count(key)) {
            Move2Head(m_mKey2Node[key]);
            return m_mKey2Node[key]->value;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (m_iCurNodeCnt == m_iCapcity && m_mKey2Node.count(key) == 0) {
            m_mKey2Node.erase(m_pRear->pre->key);
            SNode* tmp = m_pRear->pre;
            tmp->key = key;
            tmp->value = value;
            m_mKey2Node[key] = tmp;
            Move2Head(tmp);
        }
        else {
            if (m_mKey2Node.count(key)) {
                m_mKey2Node[key]->value = value;
                Move2Head(m_mKey2Node[key]);
            }
            else {
                SNode* newNode = new SNode(key, value);
                m_mKey2Node[key] = newNode;
                InsertHead(newNode);
                m_iCurNodeCnt++;
            }
        }
    }

private:
    void Move2Head(SNode* _node) {
        _node->pre->post = _node->post;
        _node->post->pre = _node->pre;
        InsertHead(_node);
    }
    void InsertHead(SNode* _node) {
        _node->post = m_pHead->post;
        _node->pre = m_pHead;
        m_pHead->post->pre = _node;
        m_pHead->post = _node;
    }
    void Remove(SNode* _node) {
        _node->pre->post = _node->post;
        _node->post->pre = _node->pre;
        SNode* tmp = _node;
        delete tmp;
        tmp = nullptr;
    }
private:
    map<int, SNode*> m_mKey2Node;
    int m_iCurNodeCnt;
    int m_iCapcity;
    SNode* m_pHead, *m_pRear;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

