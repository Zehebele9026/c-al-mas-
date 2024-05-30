#ifndef NONCIRCULARSINGLYLINKEDLIST_H
#define NONCIRCULARSINGLYLINKEDLIST_H

#include <string>

struct Node {
    std::string info;
    Node* next;

    Node() : info(""), next(nullptr) {}
    Node(std::string val) : info(val), next(nullptr) {}
};

class nonCircularSinglyLinkedList {
private:
    Node* head;

public:
    nonCircularSinglyLinkedList();
    ~nonCircularSinglyLinkedList();
    void insert(const std::string& val);
    void remove(const std::string& val);
    bool search(const std::string& val) const;
    void printList() const;
};

#endif 
