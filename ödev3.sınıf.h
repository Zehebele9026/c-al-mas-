#ifndef NONCIRCULARDOUBLYLINKEDLIST_H
#define NONCIRCULARDOUBLYLINKEDLIST_H

#include <string>

struct Node {
    std::string info;
    Node* next;
    Node* prev;

    Node() : info(""), next(nullptr), prev(nullptr) {}
    Node(std::string val) : info(val), next(nullptr), prev(nullptr) {}
};

class nonCircularDoublyLinkedList {
private:
    Node* head;

public:
    nonCircularDoublyLinkedList();
    ~nonCircularDoublyLinkedList();
    void insert(const std::string& val);
    void remove(const std::string& val);
    bool search(const std::string& val) const;
    void printList() const;
};

#endif 