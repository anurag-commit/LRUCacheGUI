#include "lrucache.h"

LRUCache::LRUCache(int capacity) : capacity(capacity) {
    head = new Node(0, "");
    tail = new Node(0, "");
    head->next = tail;
    tail->prev = head;
}

LRUCache::~LRUCache() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void LRUCache::addNode(Node* node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
}

void LRUCache::removeNode(Node* node) {
    Node* prevNode = node->prev;
    Node* nextNode = node->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
}

void LRUCache::moveToFront(Node* node) {
    removeNode(node);
    addNode(node);
}

LRUCache::Node* LRUCache::removeTail() {
    Node* res = tail->prev;
    removeNode(res);
    return res;
}

QString LRUCache::get(int key) {
    auto it = cacheMap.find(key);
    if (it == cacheMap.end()) {
        return "NOT FOUND";
    }
    Node* node = it->second;
    moveToFront(node);
    return node->value;
}

QString LRUCache::put(int key, const QString& value) {
    auto it = cacheMap.find(key);
    if (it != cacheMap.end()) {
        // Update existing key
        Node* node = it->second;
        node->value = value;
        moveToFront(node);
        return ""; // no eviction
    } else {
        // Insert new key
        Node* newNode = new Node(key, value);
        cacheMap[key] = newNode;
        addNode(newNode);

        if (cacheMap.size() > capacity) {
            Node* tailNode = removeTail();
            QString removedKey = QString::number(tailNode->key);
            cacheMap.erase(tailNode->key);
            delete tailNode;
            return removedKey; // eviction happened
        }
        return "";
    }
}

std::vector<std::pair<int, QString>> LRUCache::getAll() {
    std::vector<std::pair<int, QString>> items;
    Node* current = head->next;
    while (current != tail) {
        items.push_back({current->key, current->value});
        current = current->next;
    }
    return items;
}
