#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
}

void DoublyLinkedList::append(std::string from, int arrival_hour, int arrival_minute, int departure_hour, int departure_minute) {
    Node* newNode = new Node;
    newNode->from = from;
    newNode->arrival_time_hour = arrival_hour;
    newNode->arrival_time_minute = arrival_minute;
    newNode->departure_time_hour = departure_hour;
    newNode->departure_time_minute = departure_minute;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
        head->next = head; // Faz o único nó apontar para si mesmo para formar uma lista circular
        head->prev = head;
    }

    else{
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

void DoublyLinkedList::printForward() {
    if (head == nullptr) {
        std::cout << "A lista está vazia." << std::endl;
        return;
    }

    Node* current = head;
    do {
        std::cout << "Destino: " << current->from
                  << ", Hora de Saida: " << current->arrival_time_hour << ":" << current->arrival_time_minute
                  << ", Hora de Chegada: " << current->departure_time_hour << ":" << current->departure_time_minute << std::endl;
        current = current->next;
    } while (current != head);
}

void DoublyLinkedList::printBackward() {
    if (head == nullptr) {
        std::cout << "A lista está vazia." << std::endl;
        return;
    }

    Node* current = head->prev;
    do {
        std::cout << "Destino: " << current->from
                  << ", Hora de Saida: " << current->arrival_time_hour << ":" << current->arrival_time_minute
                  << ", Hora de Chegada: " << current->departure_time_hour << ":" << current->departure_time_minute << std::endl;
        current = current->prev;
    } while (current != head->prev);
}
