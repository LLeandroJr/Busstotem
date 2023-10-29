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
        iterator_list it(list_m_head);

        return it;
    }

    iterator_list end(){
        iterator_list it(list_m_head);
        return it;
    }

    iterator_list before_end(){
        iterator_list it(list_m_head->listPrev);
        return it;
    }
    // construtor que cria uma lista vazia
    // Construtor: cria lista vazia
    List(){
        list_m_head=nullptr;
        list_m_size=0;
    }
    // destrutor
    ~List(){
        clear();
    }

    void printAll() const{
        if(list_m_head==nullptr){
            std::cout<<"A lista está vazia.\n";
            return;
        }

        NodeList* temp=list_m_head;

        do{
            std::cout<<"Destino: "
                     <<temp->listData.showFrom()
                     
            <<"\n Horario de saida: "
                     <<temp->listData.showStartTimeHour()
                     <<" : "
                     <<temp->listData.showStartTimeMin()

            <<"\n Horario de chegada"
                     <<temp->listData.showEndTimeHour()
                     <<" : "
                     <<temp->listData.showEndTimeMin()
            <<std::endl;
            temp=temp->listNext;
        }while(temp!=list_m_head);
    }

    void rprintAll(){
        if(list_m_head==nullptr){
            std::cout<<"A lista está vazia.\n";
            return;
        }

        NodeList* temp=list_m_head->listPrev;

        do{
            std::cout<<"Destino: "
                     <<temp->listData.showFrom()
                     
            <<"\n Horario de saida: "
                     <<temp->listData.showStartTimeHour()
                     <<" : "
                     <<temp->listData.showStartTimeMin()

            <<"\n Horario de chegada"
                     <<temp->listData.showEndTimeHour()
                     <<" : "
                     <<temp->listData.showEndTimeMin()
            <<std::endl;
            temp=temp->listPrev;
        }while(temp!=list_m_head->listPrev);
    }

    void printIt(const iterator_list& it) const{
        std::cout<<"Destino: "
                 <<it.listPtr->listData.showFrom()
                 
        <<"\n Horario de saida: "
                 <<it.listPtr->listData.showStartTimeHour()
                 <<" : "
                 <<it.listPtr->listData.showStartTimeMin()

        <<"\n Horario de chegada"
                 <<it.listPtr->listData.showEndTimeHour()
                 <<" : "
                 <<it.listPtr->listData.showEndTimeMin()
        <<std::endl;
    }

    bool empty() const{
        return list_m_size==0;
    }

    unsigned size()const{
        return list_m_size;
    }

    // função que limpa a List.h
    void clear(){
        while(list_m_head!=nullptr){
            NodeList* temp=list_m_head;
            list_m_head=temp->listNext;
            delete temp;
        }

        list_m_size=0;
    }

    // função que apaga uma parada especifica da linha de onibus

    void erase(iterator_list& it) {
        if (empty()) {
            return; // Não retorna nada pois a lista ja esta vazia
        }
        NodeList* nodeToDelete = it.listPtr;
        NodeList* prevNode = nodeToDelete->listPrev;
        NodeList* nextNode = nodeToDelete->listNext;

        if (list_m_size == 1) {
            // Se existir somente um nó na lista, limpe a lista
            list_m_head = nullptr;
        } else {
            prevNode->listNext = nextNode;
            nextNode->listPrev = prevNode;

            if ( nodeToDelete == list_m_head) {
                // Se o nó que será apagado é o nó cabeça, atualize a m_head
                list_m_head = nextNode;
            }
        }

        delete nodeToDelete;
        --list_m_head;

    }

    /*

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

    */
    iterator_list insert(const unsigned& inserir_apos){
        NodeList* thisNode=list_m_head;
        unsigned token_rage{};

        if(!empty()){
            do{
                ++token_rage;
                thisNode=thisNode->listNext;
            }while(thisNode!=list_m_head);
        }
        NodeList* temp=thisNode->listNext;
        thisNode->listNext=new NodeList(Pass(),temp->listNext->listPrev,temp->listNext);
        temp->listNext->listPrev=thisNode->listNext;

        ++list_m_size;

    }

    void erase(){

    }
};

#endif
