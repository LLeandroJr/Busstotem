#ifndef NODELIST_H
#define NODELIST_H
#include "Pass.h"

class NodeList{
    friend class List;
    friend class iterator_list;
private:
    Pass listData;
    NodeList* listPrev;
    NodeList* listNext;
public:
    NodeList(Pass listData,NodeList* listPrevPtr,NodeList* listNextPtr){
        this->listData=listData;
        listPrev=listPrevPtr;
        listNext=listNextPtr;
    }
};

#endif