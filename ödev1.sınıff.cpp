#include 'nonCircularSinglyLinkedList.h'
#include <iostream>

nonCircularSinglyLinkedList::nonCircularSinglyLinkedList() : head(nullptr) {}

nonCircularSinglyLinkedList::~nonCircularSinglyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void nonCircularSinglyLinkedList::insert(const std::string& val) {
    Node* newNode = new Node(val);
    if (head == nullptr || head->info > val) {
        newNode->next = head;
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
        current->next = newNode;
    }
}

void nonCircularSinglyLinkedList::remove(const std::string& val) {
    if (head == nullptr) return;
    if (head->info == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* current = head;
    while (current->next != nullptr && current->next->info != val) {
        current = current->next;
    }
    if (current->next == nullptr) return;
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

bool nonCircularSinglyLinkedList::search(const std::string& val) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->info == val) return true;
        current = current->next;
    }
    return false;
}

void nonCircularSinglyLinkedList::printList() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->info << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
