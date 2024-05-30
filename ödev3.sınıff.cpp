#include "nonCircularDoublyLinkedList.h"
#include <iostream>

nonCircularDoublyLinkedList::nonCircularDoublyLinkedList() : head(nullptr) {}

nonCircularDoublyLinkedList::~nonCircularDoublyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void nonCircularDoublyLinkedList::insert(const std::string& val) {
    Node* newNode = new Node(val);
    if (head == nullptr || head->info > val) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->info < val) {
            current = current->next;
        }
        if (current->next != nullptr && current->next->info == val) {
            delete newNode;
            return;
        }
        newNode->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void nonCircularDoublyLinkedList::remove(const std::string& val) {
    if (head == nullptr) return;
    if (head->info == val) {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return;
    }
    Node* current = head;
    while (current != nullptr && current->info != val) {
        current = current->next;
    }
    if (current == nullptr) return;
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }
    delete current;
}

bool nonCircularDoublyLinkedList::search(const std::string& val) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->info == val) return true;
        current = current->next;
    }
    return false;
}

void nonCircularDoublyLinkedList::printList() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->info << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
