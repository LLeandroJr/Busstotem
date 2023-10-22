#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include "Node.h"
#include "List.h"
#include <iostream>

class ForwardList{
private:
    Node* m_head{};
    Node* m_tail{};
    unsigned m_size{};
public:
    iterator begin(){
        iterator it(m_head->next);
        return it;
    }

    iterator before_begin(){
        iterator it(m_head);
        return it;
    }

    iterator end(){
        iterator it(nullptr);
        return it;
    }

    iterator before_end(){
        iterator it(m_tail);
        return it;
    }
    // Construtor: cria lista vazia
    ForwardList(){
        m_head=m_tail=new Node(Data(),nullptr,nullptr);
        m_size=0;
    }
    // destrutor
    ~ForwardList(){
        clear();
        delete m_head;
    }

    void print() const{

    }

    const bool empty() const{
        return m_size==0;
    }

    const unsigned size()const{
        return m_size;
    }

    // função incompleta, falta a função clear da list
    // Complexidade O(n*m)
    void clear(){
        Node* temp=m_head->next;

        while(temp!=nullptr){

            //m_head->next->list->clear(); // chamando a função clear da List.h
            m_head->next->list->~List(); // chamando a função clear da List.h

            m_head->next=temp->next;
            delete temp;
            temp=m_head->next;
        }
        m_tail=m_head;
        m_size=0;
    }

    void insert(){

    }

    void erase(){

    }

    // by:diogo
    void append(std::string name, int id) {
        Node* new_node = new Node(name, id);
        new_node->next = m_head;
        m_head = new_node;
    }

    // by:diogo
    void display() {
        Node* current = m_head;
        while (current != nullptr) {
            std::cout << "Name: " << current->name << ", ID: " << current->id << std::endl;
            current = current->next;
        }
    }
};

class iterator{
    friend class ForwardList;
private:
    Node* ptr;
public:
    iterator(Node *point){
        ptr=point;
    }

    Data& operator*() {
        return ptr->data;
    }
    
    unsigned& operator*(unsigned) {
        return ptr->data.ID;
    }

    std::string& operator*(std::string) {
        return ptr->data.company;
    }

    std::string& operator*(std::string) {
        return ptr->data.to;
    }

    bool operator==(const iterator& it){
        return ptr==it.ptr;
    }

    bool operator!=(const iterator& it){
        return ptr!=it.ptr;
    }

    iterator& operator++(){
        ptr=ptr->next;
        return *this;
    }

    iterator operator++(int){
        iterator temp=*this;
        ptr=ptr->next;
        return temp;
    }
};

#endif
