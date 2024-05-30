#include "circularSinglyLinkedList.h"
#include <iostream>

circularSinglyLinkedList::circularSinglyLinkedList() : head(nullptr) {}

circularSinglyLinkedList::~circularSinglyLinkedList() {
    if (head == nullptr) return;
    Node* current = head->next;
    while (current != head) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    delete head;
}

void circularSinglyLinkedList::insert(const std::string& val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
    } else if (head->info >= val) {
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        newNode->next = head;
        tail->next = newNode;
        if (head->info > val) {
            head = newNode;
        }
    } else {
        Node* current = head;
        while (current->next != head && current->next->info < val) {
            current = current->next;
        }
        if (current->next->info == val) {
            delete newNode;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void circularSinglyLinkedList::remove(const std::string& val) {
    if (head == nullptr) return;
    if (head->info == val) {
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            tail->next = head->next;
            delete head;
            head = tail->next;
        }
        return;
    }
    Node* current = head;
    while (current->next != head && current->next->info != val) {
        current = current->next;
    }
    if (current->next->info == val) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

bool circularSinglyLinkedList::search(const std::string& val) const {
    if (head == nullptr) return false;
    Node* current = head;
    do {
        if (current->info == val) return true;
        current = current->next;
    } while (current != head);
    return false;
}

void circularSinglyLinkedList::printList() const {
    if (head == nullptr) return;
    Node* current = head;
    do {
        std::cout << current->info << " ";
        current = current->next;
    } while (current != head);
    std::cout << std::endl;
}
