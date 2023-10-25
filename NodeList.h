#ifndef NODELIST_H
#define NODELIST_H
#include "Pass.h"

// Classe contém os atributos do tipo Pass, NodeList* e NodeList*.
// Respectivamente:
// listData: contém os atributos do objeto da classe Pass.
// listPrev: ponteiro para o nó anterior.
// listNext: ponteiro para o próximo nó.
class NodeList{
    friend class List;
    friend class iterator_list;
private:
    Pass listData; // Contém os atributos do objeto da classe Pass.
    NodeList* listPrev; // Ponteiro para o nó anterior.
    NodeList* listNext; //Ponteiro para o próximo nó.
public:
    // Construtor que atribui ao objeto da classe NodeList.
    // Node(Pass <listData>,NodeList* <listPrevPtr>,NodeList* <listnextPtr>)
    NodeList(Pass listData,NodeList* listPrevPtr,NodeList* listNextPtr){
        this->listData=listData;
        listPrev=listPrevPtr;
        listNext=listNextPtr;
    }
};

#endif