#ifndef NODE_H
#define NODE_H
#include "Data.h"
#include "NodeList.h"
#include "List.h"
#include <iostream> // implementacao by Diogo

class Node{
    friend class ForwardList;
    friend class iterator;
private:
    // o nó deve ter três informações principais
    // informação que o nó guarda
    // o ponteiro que aponta para a lista circula que por vez contém a pass 
    // 0 ponteiro para o póximo nó
    Data data;
    List* list;
    Node* next;
public:
    Node(Data data,List* listPtr,Node* nextPtr){
        this->data=data;
        list=listPtr;
        next=nextPtr;
    }
};

#endif
