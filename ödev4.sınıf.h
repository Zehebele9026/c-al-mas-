#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H

#include <string>

struct Node {
    std::string info;
    Node* next;
    Node* prev;

    Node() : info(""), next(nullptr), prev(nullptr) {}
    Node(std::string val) : info(val), next(nullptr), prev(nullptr) {}
};

class circularDoublyLinkedList {
private:
    Node* head;

public:
    circularDoublyLinkedList();
    ~circularDoublyLinkedList();
    void insert(const std::string& val);
    void remove(const std::string& val);
    bool search(const std::string& val) const;
    void printList() const;
};

#endif 
