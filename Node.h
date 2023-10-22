#ifndef NODE_H
#define NODE_H
#include "Data.h"
#include "NodeList.h"
#include "List.h"

// Classe contém os atributos do tipo Data, List* e Node*.
// Respectivamente:
// data: contém os atributos do objeto da classe Data.
// list: ponteiro para lista duplamente encadeada circular.
// next: ponteiro para o próximo nó.
class Node{
    friend class ForwardList;
    friend class iterator;
private:
    Data data; // Contém os atributos do objeto da classe Data.
    List* list; // Ponteiro para lista duplamente encadeada circular.
    Node* next; // Ponteiro para o próximo nó.
public:
    // Construtor que atribui ao objeto da classe Node.
    // Node(Data <data>,List* <listPtr>,Node* <nextPtr>)
    Node(Data data,List* listPtr,Node* nextPtr){
        this->data=data;
        list=listPtr;
        next=nextPtr;
    }
};

#endif
