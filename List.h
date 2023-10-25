#ifndef LIST_H
#define LIST_H
#include "NodeList.h"
#include "Pass.h"
#include <iostream>

class iterator_list{
    friend class List;
private:
    NodeList* listPtr;
public:
    iterator_list(NodeList *point){
        listPtr=point;
    }

    Pass& operator*() {
        return listPtr->listData;
    }

    bool operator==(const iterator_list& it){
        return listPtr==it.listPtr;
    }

    bool operator!=(const iterator_list& it){
        return listPtr!=it.listPtr;
    }

    iterator_list& operator++(){
        listPtr=listPtr->listNext;
        return *this;
    }

    iterator_list operator++(int){
        iterator_list temp=*this;
        listPtr=listPtr->listNext;
        return temp;
    }

    iterator_list& operator--(){
        listPtr=listPtr->listPrev;
        return *this;
    }

    iterator_list operator--(int){
        iterator_list temp=*this;
        listPtr=listPtr->listPrev;
        return temp;
    }
};

class List{
private:
    NodeList* list_m_head{};
    unsigned list_m_size{};
public:
    iterator_list begin(){
        iterator_list it(list_m_head->listNext);
        return it;

    }

    iterator_list before_begin(){
        iterator_list it(list_m_head);
        return it;
    }

    iterator_list end(){
        iterator_list it(nullptr);
        return it;
    }

    iterator_list before_end(){
        iterator_list it(list_m_head->listPrev);
        return it;
    }
    // construtor que cria uma lista vazia
    // Construtor: cria lista vazia
    List(){
        list_m_head=new NodeList(Pass(),nullptr,nullptr);
        list_m_head->listPrev=list_m_head;
        list_m_head->listNext=list_m_head;
        list_m_size=0;
    }
    // destrutor
    ~List(){
        clear();
        delete list_m_head;
    }

    void print() const{

    }

    //-----------------------------------------------------------
    void printForward() {
        if (list_m_head == nullptr) {
            std::cout << "A lista está vazia." << std::endl;
            return;
        }

        NodeList* current = list_m_head;
        do {
            std::cout << "Destino: " << current->listData.showfrom()
                    << ", Hora de Saida: " 
                    << current->listData.showStartTimeHour() << ":" << current->listData.showStartTimeMin()
                    << ", Hora de Chegada: " 
                    << current->listData.showEndTimeHour() << ":" << current->listData.showEndTimeMin()
                    << std::endl;
            current = current->listNext;
        } while (current != list_m_head);
    }

    void printBackward() {
        if (list_m_head == nullptr) {
            std::cout << "A lista está vazia." << std::endl;
            return;
        }

        NodeList* current = list_m_head->listPrev;
        do {
            std::cout << "Destino: " << current->listData.showfrom()
                    << ", Hora de Saida: " 
                    << current->listData.showStartTimeHour() << ":" << current->listData.showStartTimeMin()
                    << ", Hora de Chegada: "
                    << current->listData.showEndTimeHour() << ":" << current->listData.showEndTimeMin() 
                    << std::endl;
            current = current->listPrev;
        } while (current != list_m_head->listPrev);
    }
    //-----------------------------------------------------------

    const bool empty() const{
        return list_m_size==0;
    }

    const unsigned size()const{
        return list_m_size;
    }
    // função que limpa a List.h
    void clear(){
        NodeList* temp=list_m_head->listNext;
        while(temp!=list_m_head){
            list_m_head->listNext=temp->listNext;
            delete temp;
            temp=list_m_head->listNext;
        }
        list_m_head->listPrev=list_m_head;

        /*
        while(list_m_head->listNext!=list_m_head){
            NodeList* temp=list_m_head->listNext;
            list_m_head->listNext=temp->listNext;
            temp->listNext->listPrev=temp->listPrev;
            delete temp;
        }
        */
        list_m_size=0;
    }

    void insert(const std::string& from,const int& startTimeHour,const int& startTimeMin,const int& endTimeHour,const int& endTimeMin){
        for(auto it=begin();it!=end();++it){

        }
        NodeList* newNodeList=new NodeList(
            Pass(
                    from,
                    startTimeHour,
                    startTimeMin,
                    endTimeHour,
                    endTimeMin
                ),
            nullptr,
            nullptr
        );

    }

    //-----------------------------------------------------------
    // NodeList(Pass listData,NodeList* listPrevPtr,NodeList* listNextPtr)
    void append(const std::string& from,const int& start_time_hour,const int& start_time_min,const int& end_time_hour,const int& end_time_min){
        NodeList* newNodeList=new NodeList(
            Pass(
                    from,
                    start_time_hour,
                    start_time_min,
                    end_time_min,
                    end_time_min
                ),
            nullptr,
            nullptr
        );
        // aqui tem erro lógico
        if (list_m_head == nullptr) {
            list_m_head = newNodeList;
            list_m_head->listNext = list_m_head; // Faz o único nó apontar para si mesmo para formar uma lista circular
            list_m_head->listPrev = list_m_head;
        }

        else{
            NodeList* tail = list_m_head->listPrev;
            tail->listNext = newNodeList;
            newNodeList->listPrev = tail;
            newNodeList->listNext = list_m_head;
            list_m_head->listPrev = newNodeList;
        }
        ++list_m_size;
    }
    //-----------------------------------------------------------



    void erase(){

    }
};

#endif
