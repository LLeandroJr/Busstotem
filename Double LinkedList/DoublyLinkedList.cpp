#include "DoublyLinkedList.h"
#include <iostream>

List::List() {
    list_m_head = nullptr;
}

void List::append(std::string from, int arrival_hour, int arrival_minute, int departure_hour, int departure_minute) {
    NodeList* newNode = new NodeList;
    newNode->from = from;
    newNode->arrival_time_hour = arrival_hour;
    newNode->arrival_time_minute = arrival_minute;
    newNode->departure_time_hour = departure_hour;
    newNode->departure_time_minute = departure_minute;
    newNode->listNext = nullptr;
    newNode->listPrev = nullptr;

    if (list_m_head == nullptr) {
        list_m_head = newNode;
        list_m_head->listNext = list_m_head; // Faz o único nó apontar para si mesmo para formar uma lista circular
        list_m_head->listPrev = list_m_head;
    }

    else{
        NodeList* tail = list_m_head->listPrev;
        tail->listNext = newNode;
        newNode->listPrev = tail;
        newNode->listNext = list_m_head;
        list_m_head->listPrev = newNode;
    }
}

void List::printForward() {
    if (list_m_head == nullptr) {
        std::cout << "A lista está vazia." << std::endl;
        return;
    }

    NodeList* current = list_m_head;
    do {
        std::cout << "Destino: " << current->from
                  << ", Hora de Saida: " << current->arrival_time_hour << ":" << current->arrival_time_minute
                  << ", Hora de Chegada: " << current->departure_time_hour << ":" << current->departure_time_minute << std::endl;
        current = current->listNext;
    } while (current != list_m_head);
}

void List::printBackward() {
    if (list_m_head == nullptr) {
        std::cout << "A lista está vazia." << std::endl;
        return;
    }

    NodeList* current = list_m_head->listPrev;
    do {
        std::cout << "Destino: " << current->from
                  << ", Hora de Saida: " << current->arrival_time_hour << ":" << current->arrival_time_minute
                  << ", Hora de Chegada: " << current->departure_time_hour << ":" << current->departure_time_minute << std::endl;
        current = current->listPrev;
    } while (current != list_m_head->listPrev);
}
