#include <bits/stdc++.h>
using namespace std;

struct LRUNode {
    int key;
    char *value;
    LRUNode *next;
    LRUNode *prev;
    LRUNode() : key(0), value(nullptr) {}
    LRUNode(int key, char *value) : key(key), value(value) {}
};

class LRUCache {
private:
    int m_capacity;
    int m_size;
    LRUNode *m_head, *m_tail; // 头结点热数据  尾节点冷数据
    unordered_map<int, LRUNode *> m_hash;
    void removeNode(LRUNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addToHead(LRUNode *node) {
        node->next = m_head->next;
        node->prev = m_head->prev;
        node->prev->next = node;
        node->next->prev = node;
    }
    LRUNode *removeTail() {
        LRUNode *node = m_tail->prev;
        removeNode(node);
        return node;
    }
    void moveToHead(LRUNode *node) {
        removeNode(node);
        addToHead(node);
    }

public:
    LRUCache(int capacity) : m_capacity(capacity), m_size(0) {
        m_head = new LRUNode();
        m_tail = new LRUNode();
        m_head->next = m_tail;
        m_tail->prev = m_head;
    }
    ~LRUCache() {
        delete m_head;
        delete m_tail;
    }
    void Push(int key, char *value) {
        if (m_hash.find(key) != m_hash.end()) {
            LRUNode *node = m_hash[key];
            node->value = value;
            moveToHead(node);
        } else {
            LRUNode *node = new LRUNode(key, value);
            m_hash[key] = node;
            if (m_size == m_capacity) {
                LRUNode *removed = removeTail();
                delete removed;
                removed = nullptr;
                --m_size;
            }
            addToHead(node);
            ++m_size;
        }
    }
    char *Get(int key) {
        if (m_hash.find(key) != m_hash.end()) {
            moveToHead(m_hash[key]);
            return m_hash[key]->value;
        } else {
            return nullptr;
        }
    }
    void Remove(int key, char *value) {
        if (m_hash.find(key) != m_hash.end() && m_hash[key]->value == value) {
            removeNode(m_hash[key]);
        }
    }
};