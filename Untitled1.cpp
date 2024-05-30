#include "nonCircularSinglyLinkedList.h"
#include <iostream>

// Yapıcı: Başlangıçta listenin başını null olarak ayarlar
nonCircularSinglyLinkedList::nonCircularSinglyLinkedList() : head(nullptr) {}

// Yıkıcı: Listedeki tüm düğümleri siler
nonCircularSinglyLinkedList::~nonCircularSinglyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

// Eleman ekleme: Listenin sıralı ve tekrar etmeyen yapısına uygun olarak yeni bir düğüm ekler
void nonCircularSinglyLinkedList::insert(const std::string& val) {
    Node* newNode = new Node(val); // Yeni düğüm oluştur
    if (head == nullptr || head->info > val) { // Eğer liste boşsa veya yeni düğüm başa eklenmeli ise
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->info < val) { // Doğru konumu bulana kadar ilerle
            current = current->next;
        }
        if (current->next != nullptr && current->next->info == val) { // Eğer düğüm zaten varsa, ekleme
            delete newNode;
            return;
        }
        newNode->next = current->next; // Yeni düğümü listeye ekle
        current->next = newNode;
    }
}

// Eleman çıkarma: Belirtilen değere sahip düğümü listeden çıkarır
void nonCircularSinglyLinkedList::remove(const std::string& val) {
    if (head == nullptr) return; // Eğer liste boşsa, çık
    if (head->info == val) { // Eğer baştaki düğüm çıkarılacaksa
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* current = head;
    while (current->next != nullptr && current->next->info != val) { // Doğru konumu bulana kadar ilerle
        current = current->next;
    }
    if (current->next == nullptr) return; // Eğer düğüm bulunamazsa, çık
    Node* temp = current->next;
    current->next = current->next->next; // Düğümü listeden çıkar
    delete temp;
}

// Eleman arama: Listede belirtilen değeri arar
bool nonCircularSinglyLinkedList::search(const std::string& val) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->info == val) return true; // Eğer düğüm bulunursa, true dön
        current = current->next;
    }
    return false; // Eğer düğüm bulunamazsa, false dön
}

// Listeyi yazdırma: Listenin tüm elemanlarını yazdırır
void nonCircularSinglyLinkedList::printList() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->info << " "; // Düğüm bilgisini yazdır
        current = current->next;
    }
    std::cout << std::endl;
}
