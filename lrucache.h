#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <QString>
#include <unordered_map>
#include <vector>
#include <utility>

class LRUCache
{
public:
    LRUCache(int capacity);
    ~LRUCache();

    // Returns value if found; else "NOT FOUND"
    QString get(int key);

    // Inserts or updates key-value pair.
    // Returns evicted key as QString if eviction happens; else empty QString
    QString put(int key, const QString& value);

    // Returns all cache items in order from most recent to least recent
    std::vector<std::pair<int, QString>> getAll();

private:
    struct Node {
        int key;
        QString value;
        Node* prev;
        Node* next;
        Node(int k, const QString& v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    std::unordered_map<int, Node*> cacheMap;
    Node* head;
    Node* tail;

    void addNode(Node* node);
    void removeNode(Node* node);
    void moveToFront(Node* node);
    Node* removeTail();
};

#endif // LRUCACHE_H
