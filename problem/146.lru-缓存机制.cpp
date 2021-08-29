/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
#include <unordered_map>
#include <iostream>
using namespace std;

struct DListNode{
    int key,val;
    DListNode *pre, *next;
    DListNode():key(0),val(0),pre(nullptr),next(nullptr){};
    DListNode(int _key, int _val) : key(_key),val(_val),pre(nullptr), next(nullptr){};
};

class LRUCache{
private:
    DListNode* head;
    DListNode* tail;
    int size;
    int capacity;
    unordered_map<int, DListNode*> m;

public:
    LRUCache(int capacity):size(0),capacity(capacity) {
        head = new DListNode();
        tail = new DListNode();
        head->next = tail;
        tail->pre = head;
    }

    void put(int key, int val) {
        if (!m.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            DListNode* node = new DListNode(key, val);
            // 添加进哈希表
            m[key] = node;
            // 添加至双向链表的头部
            insertHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                DListNode* removed = deleteTail();
                // 删除哈希表中对应的项
                m.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        }
        else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DListNode* node = m[key];
            node->val = val;
            movetohead(node);
        }
    }
    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        movetohead(m[key]);
        return m[key]->val;
    }

    void movetohead(DListNode* node){
        //? 首先删除该节点与周围节点的连接
        moveNode(node);
        insertHead(node);
    }
    void moveNode(DListNode* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    void insertHead(DListNode* node) {
        head->next->pre = node;
        node->next = head->next;
        head->next = node;
        node->pre = head;
    }
    
    DListNode* deleteTail() {
        DListNode* tmp = tail->pre;
        moveNode(tmp);
        return tmp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

struct DListNode{
    int key,val;
    DListNode *pre, *next;
    DListNode():key(0),val(0),pre(nullptr),next(nullptr){};
    DListNode(int _key, int _val) : key(_key),val(_val),pre(nullptr), next(nullptr){};
};

class LRUCache{
private:
    DListNode* head;
    DListNode* tail;
    int size;
    int capacity;
    unordered_map<int, DListNode*> m;

public:
    LRUCache(int _capacity):size(0),capacity(_capacity) {
        head = new DListNode();
        tail = new DListNode();
        head->next = tail;
        tail->pre = head;
    }

    void put(int key, int val) {
        if (m.find(key) == m.end()) {
            m[key] = new DListNode(key, val);
            
        }
        else {
            m[key]->val = val;
        }
        if (size == capacity) {
            DListNode* tmp = deleteTail();
            free(tmp);
        }
        else {
            size++;
        }
        movetohead(m[key]);
    }
    int get(int key) {
        return m[key]->val;
        movetohead(m[key]);
    }

    void movetohead(DListNode* node){
        //? 首先删除该节点与周围节点的连接
        moveNode(node);
        insertHead(node);
    }
    void moveNode(DListNode* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    void insertHead(DListNode* node) {
        head->next->pre = node;
        node->next = head->next;
        head->next = node;
        node->pre = head;
    }
    
    DListNode* deleteTail() {
        DListNode* tmp = tail->pre;
        moveNode(tmp);
        return tmp;
    }



};
// @lc code=end

