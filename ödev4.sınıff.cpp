#include "circularDoublyLinkedList.h"
#include <iostream>

circularDoublyLinkedList::circularDoublyLinkedList() : head(nullptr) {}

circularDoublyLinkedList::~circularDoublyLinkedList() {
    if (head == nullptr) return;
    Node* current = head->next;
    while (current != head) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    delete head;
}

void circularDoublyLinkedList::insert(const std::string& val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else if (head->info >= val) {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
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
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

void circularDoublyLinkedList::remove(const std::string& val) {
    if (head == nullptr) return;
    if (head->info == val) {
        Node* tail = head->prev;
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            tail->next = head->next;
            head->next->prev = tail;
            Node* temp = head;
            head = tail->next;
            delete temp;
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
        current->next->prev = current;
        delete temp;
    }
}

bool circularDoublyLinkedList::search(const std::string& val) const {
    if (head == nullptr) return false;
    Node* current = head;
    do {
        if (current->info == val) return true;
        current = current->next;
    } while (current != head);
    return false;
}

void circularDoublyLinkedList::printList() const {
    if (head == nullptr) return;
    Node* current = head;
    do {
        std::cout << current->info << " ";
        current = current->next;
    } while (current != head);
    std::cout << std::endl;
}
