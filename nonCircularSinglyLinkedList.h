#ifndef NONCIRCULARSINGLYLINKEDLIST_H
#define NONCIRCULARSINGLYLINKEDLIST_H

#include <string>

// Düğüm yapısı tanımı
struct Node {
    std::string info; // Düğümde saklanan bilgi
    Node* next; // Bir sonraki düğüme işaretçi

    Node() : info(""), next(nullptr) {} // Parametresiz yapıcı
    Node(std::string val) : info(val), next(nullptr) {} // Parametreli yapıcı
};

// nonCircularSinglyLinkedList sınıfı tanımı
class nonCircularSinglyLinkedList {
private:
    Node* head; // Listenin başını gösteren işaretçi

public:
    nonCircularSinglyLinkedList(); // Yapıcı
    ~nonCircularSinglyLinkedList(); // Yıkıcı

    void insert(const std::string& val); // Eleman ekleme
    void remove(const std::string& val); // Eleman çıkarma
    bool search(const std::string& val) const; // Eleman arama
    void printList() const; // Listeyi yazdırma
};

#endif // NONCIRCULARSINGLYLINKEDLIST_H
