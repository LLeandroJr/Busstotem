#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "Node.h"

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList();
    void append(std::string from, int arrival_hour, int arrival_minute, int departure_hour, int departure_minute);
    void printForward();
    void printBackward();
};

#endif
