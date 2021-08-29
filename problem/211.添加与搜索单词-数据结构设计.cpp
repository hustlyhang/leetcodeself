/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
#include <string>
#include <iostream>

using namespace std;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct Node {
        Node* next[26] = {nullptr};
        bool is_end;
        Node() {
            is_end = false;
        }
    };

    Node* root = nullptr;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        //cout<<"in add"<<' '<<word<<endl;
        Node *tmp = root;
        for (auto c : word) {
            if (tmp->next[c - 'a'] == nullptr) {
                tmp->next[c - 'a'] = new Node();
            }
            tmp = tmp->next[c - 'a'];
        }
        tmp->is_end = true;
    }
    
    bool search(string word) {
        //cout<<"in search"<<endl;
        return searchCore(word, root, 0);
    }

    bool searchCore(string& word, Node* root, int start) {
        if (start == word.size()) return root->is_end;
        if (word[start] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (root->next[i] != nullptr && searchCore(word, root->next[i], start + 1)) {
                    return true;
                }
            }
        }
        else {
            if (root->next[word[start] - 'a']) return searchCore(word, root->next[word[start] - 'a'], start + 1);
            else return false;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

