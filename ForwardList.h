#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include "Node.h"
#include "Data.h"
#include "List.h"
#include <iostream>

class iterator_forwardList{
    friend class ForwardList;
private:
    Node* ptr;
public:
    iterator_forwardList(Node *point){
        ptr=point;
    }
    
    Data& operator*() {
        return ptr->data;
    }

    bool operator==(const iterator_forwardList& it){
        return ptr==it.ptr;
    }

    bool operator!=(const iterator_forwardList& it){
        return ptr!=it.ptr;
    }

    iterator_forwardList& operator++(){
        ptr=ptr->next;
        return *this;
    }

    iterator_forwardList operator++(int){
        iterator_forwardList temp=*this;
        ptr=ptr->next;
        return temp;
    }
};

class ForwardList{
private:
    Node* m_head{}; // Nó sentinela tipo Node que aponta para o primeiro nó da ForwardList
    Node* m_tail{}; // Ponteiro tipo Node que aponta para o último nó da ForwardList
    unsigned m_size{}; // Tamanho da ForwardList
public:
    // Retorna o primeiro nó da ForwardList
    // Complexidade: O(1)
    iterator_forwardList begin(){
        iterator_forwardList it(m_head->next);
        return it;
    }

    // Retorna o nó sentinela da ForwardList
    // Complexidade: O(1)
    iterator_forwardList before_begin(){
        iterator_forwardList it(m_head);
        return it;
    }
    // Retorna o fim da ForwardList
    // Complexidade: O(1)
    iterator_forwardList end(){
        iterator_forwardList it(nullptr);
        return it;
    }

    // Retorna o último nó da ForwardList
    // Complexidade: O(1)
    iterator_forwardList before_end(){
        iterator_forwardList it(m_tail);
        return it;
    }

    // Construtor que cria a ForwardList vazia.
    ForwardList(){
        m_head=m_tail=new Node(Data(),nullptr,nullptr);
        m_size=0;
    }
    // Destrutor da classe ForwardList
    ~ForwardList(){
        clear();
        delete m_head;
        delete m_tail;
    }
    
    // Imprime os atributos do objeto da classe Data,
    // associados ao Node da ForwardList.
    // Complexidade: O(n)
    void print() const{
        Node* temp=m_head->next;
        while(temp!=nullptr){
            std::cout<<"ID: "<<temp->data.showID()<<"\n";
            std::cout<<"Company: "<<temp->data.showCompany()<<"\n";
            std::cout<<"TO: "<<temp->data.showTo()<<"\n";
            temp=temp->next;
        }
    }

    // Retorna um booleano, caso a ForwardList esteja vazia, verdade e senão falso. 
    // Complexidade: O(1)
    bool empty() const{
        return m_size==0;
    }

    // Retorna o tamanho da ForwardList
    // Complexidade: O(1)
    unsigned size()const{
        return m_size;
    }

    // Função que apaga todas as linhas da ForwardList.
    // Complexidade: O(n*m)
    void clear(){
        Node* temp=m_head->next;
        while(temp!=nullptr){
            // Chama o destrutor da List
            //m_head->next->list->~List();
            m_head->next=temp->next;
            delete temp;
            temp=m_head->next;
        }
        m_tail=m_head;
        m_size=0;
    }
    
    // função para testar apenas
    void insert(const int& numero,const std::string& companhia,const std::string& destino){
         m_head->next=new Node(Data(numero,companhia,destino),nullptr,nullptr);
    }

    void erase(){

    }
};

#endif
