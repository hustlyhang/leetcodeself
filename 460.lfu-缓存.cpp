/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start
#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;

struct DListNode{
    int key,val,fre;
    DListNode* pre, *next;
    DListNode(int _key, int _val):key(_key),val(_val),fre(0){};
};

class LFUCache {
private:
    int size;
    int capacity;
    map<int, DListNode*> mf; //? 当前频率下的节点
    unordered_map<int, DListNode*> mk; //? key值所对应的节点
public:
    LFUCache(int capacity) {
        //? 初始化容量和当前大小，以及两个map
        size = 0;
        capacity = capacity;
    }
    
    int get(int key) {
        cout<<"get"<<endl;
        if (mk.count(key)) {
            mk[key]->fre++;
            if (mf.count(mk[key]->fre)) {
                removeNode(mk[key]);
                addHead(mf[mk[key]->fre], mk[key]);
            }
            else {
                DListNode* head = new DListNode(0,0);
                DListNode* tail = new DListNode(0,0);
                head->next = tail;
                tail->pre = head;
                mf[mk[key]->fre] = head;
                removeNode(mk[key]);
                addHead(mf[mk[key]->fre], mk[key]);
            }
            return mk[key]->val;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        cout<<"put"<<endl;
        //? 如果已经存在当前节点 就更新
        cout<<"mk.count(key) = "<< mk.count(key)<<endl;
        if (mk.count(key)) {

            mk[key]->val = value;
            mk[key]->fre ++;
            //? 然后更新在mf中的位置
            if (mf.count(mk[key]->fre)) {
                removeNode(mk[key]);
                addHead(mf[mk[key]->fre], mk[key]);
            }
            else {
                DListNode* head = new DListNode(0,0);
                DListNode* tail = new DListNode(0,0);
                head->next = tail;
                tail->pre = head;
                cout<<"make"<<endl;

                mf[mk[key]->fre] = head;
                removeNode(mk[key]);
                addHead(mf[mk[key]->fre], mk[key]);
            }
        }
        else {
            //? 如果不存在当前节点 判断当前大小，是否删除
            mk[key] = new DListNode(key, value);
            cout<<"make"<<endl;
            mk[key]->fre = 1;
            cout<<"make1"<<endl;

            if (mf.count(mk[key]->fre)) {

                addHead(mf[mk[key]->fre], mk[key]);
                cout<<"make2"<<endl;

            }
            else {
                cout<<"make3"<<endl;
                
                DListNode* head = new DListNode(0,0);
                DListNode* tail = new DListNode(0,0);
                head->next = tail;
                tail->pre = head;
                mf[mk[key]->fre] = head;
                addHead(mf[mk[key]->fre], mk[key]);
                cout<<"make4"<<endl;

            }
            size++;
            cout<<"size="<<size<<endl;
        }
        if (size > capacity) {
            for (auto d : mf) {
                if (d.second->next->next == nullptr) continue;
                DListNode* tmp = d.second;
                while (tmp->next!=nullptr) tmp = tmp->next;
                DListNode* fe = tmp->pre;
                removeNode(fe);
                free(fe);
                fe = nullptr;
            }
            size--;
        }
    }

    void removeNode(DListNode* node) {
        node->next->pre = node->pre;
        node->pre->next = node->next;
    }

    void addHead(DListNode* Head, DListNode* node) {
        Head->next->pre = node;
        node->next = Head->next;
        Head->next = node;
        node->pre = Head;
    }
};
// 缓存的节点信息
struct Node {
    int key, val, freq;
    Node(int _key,int _val,int _freq): key(_key), val(_val), freq(_freq){}
};
class LFUCache {
    int minfreq, capacity;
    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;
public:
    LFUCache(int _capacity) {
        minfreq = 0;
        capacity = _capacity;
        key_table.clear();
        freq_table.clear();
    }
    
    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        if (it == key_table.end()) return -1;
        list<Node>::iterator node = it -> second;
        int val = node -> val, freq = node -> freq;
        freq_table[freq].erase(node);
        // 如果当前链表为空，我们需要在哈希表中删除，且更新minFreq
        if (freq_table[freq].size() == 0) {
            freq_table.erase(freq);
            if (minfreq == freq) minfreq += 1;
        }
        // 插入到 freq + 1 中
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();
        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 缓存已满，需要进行删除操作
            if (key_table.size() == capacity) {
                // 通过 minFreq 拿到 freq_table[minFreq] 链表的末尾节点
                auto it2 = freq_table[minfreq].back();
                key_table.erase(it2.key);
                freq_table[minfreq].pop_back();
                if (freq_table[minfreq].size() == 0) {
                    freq_table.erase(minfreq);
                }
            } 
            freq_table[1].push_front(Node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        } else {
            // 与 get 操作基本一致，除了需要更新缓存的值
            list<Node>::iterator node = it -> second;
            int freq = node -> freq;
            freq_table[freq].erase(node);
            if (freq_table[freq].size() == 0) {
                freq_table.erase(freq);
                if (minfreq == freq) minfreq += 1;
            }
            freq_table[freq + 1].push_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};


/******************************************************************/
struct Node{
    int key;
    int value;
    Node *left;
    Node *right;
    Node(int _key,int _value): key(_key), value(_value) {}
};

class doublelist{
    int size;
    Node *head;
    Node *tail;
public:
    doublelist(){
        size=0;
        head=new Node(-1, -1);
        tail=new Node(-1, -1);
        head->right=tail;
        tail->left=head;
    }

    int getSize(){
        return size;
    }

    void insertAsFirst(Node* node){
        node->left=head;
        node->right=head->right;
        head->right=node;
        node->right->left=node;
        size++;
    }

    void remove(Node *node){
        node->left->right=node->right;
        node->right->left=node->left;
        delete node;
        size--;
    }

    Node* getLast(){
        return tail->left;
    }

    void removeLast(){
        remove(tail->left);
    }
};


class LFUCache {
    int capacity;
    int size;
    int minFreq;
    unordered_map<int, int> keyToFreq;
    unordered_map<int, Node*> keyToNode;
    unordered_map<int, doublelist*> freqToKeys;
public:
    LFUCache(int _capacity) {
        capacity=_capacity;
        size=0;
        minFreq=0;
    }
    
    int get(int key) {
        if(keyToNode.count(key)==0){
            return -1;
        }
        
        Node* tmp=keyToNode[key];
        int value=tmp->value;
        int freq=keyToFreq[key];

        Node* node=new Node(key, value);

        freqToKeys[freq]->remove(tmp);
        if(freqToKeys[freq]->getSize()==0){
            freqToKeys.erase(freq);
            if(freq==minFreq){
                minFreq++;
            }
        }
        if(freqToKeys.count(freq+1)==0){
            freqToKeys[freq+1]=new doublelist();
        }
        freqToKeys[freq+1]->insertAsFirst(node);
        keyToFreq[key]++;
        keyToNode[key]=node;

        return value;
    }
    
    void put(int key, int value) {
        if(capacity==0){
            return;
        }
        if(keyToNode.count(key)==0){
            if(size==capacity){
                Node* tmp=freqToKeys[minFreq]->getLast();
                int tmp_key=tmp->key;
                keyToFreq.erase(tmp_key);
                keyToNode.erase(tmp_key);
                freqToKeys[minFreq]->remove(tmp);
                if(freqToKeys[minFreq]->getSize()==0){
                    freqToKeys.erase(minFreq);
                }
                size--;
            }

            minFreq=1;
            Node* node=new Node(key, value);
            keyToFreq[key]=1;
            keyToNode[key]=node;
            if(freqToKeys.count(1)==0){
                freqToKeys[1]=new doublelist();
            }
            freqToKeys[1]->insertAsFirst(node);
            size++;
        }else{
            keyToNode[key]->value=value;
            get(key);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

