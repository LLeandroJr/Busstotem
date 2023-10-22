#include "ForwardList.h"
#include <iostream>

ForwardList::ForwardList() : m_head(nullptr) {}

ForwardList::~ForwardList() {
    Node* current = m_head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void ForwardList::append(std::string name, int id) {
    Node* new_node = new Node(name, id);
    new_node->next = m_head;
    m_head = new_node;
}

void ForwardList::display() {
    Node* current = m_head;
    while (current != nullptr) {
        std::cout << "Name: " << current->name << ", ID: " << current->id << std::endl;
        current = current->next;
    }
}
