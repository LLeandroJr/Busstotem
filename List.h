#ifndef LIST_H
#define LIST_H
#include "NodeList.h"
#include <iostream>

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

    void insert(){

    }

    void erase(){

    }
};

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
    
    std::string& operator*(std::string) {
        return listPtr->listData.from;
    }

    std::string& operator*(std::string) {
        return listPtr->listData.startTime;
    }

    std::string& operator*(std::string) {
        return listPtr->listData.endTime;
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

#endif
