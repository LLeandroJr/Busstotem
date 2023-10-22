#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <stdexcept>

// classe que implementa um nó da lsita duplamente encadeada
class Node{
    friend class list;
private:
    int data; // o valor a ser guardado no node
    Node* prev; // ponteiro para o node anterior
    Node* next; // ponteiro para o proximo node
public:
    Node(const int& val,Node* ptrPrev,Node* ptrNext){
        data=val;
        prev=ptrPrev;
        next=ptrNext;
    }
    // destrutor de teste
    ~Node(){
        std::cout<<"liberado: "<< data << "\n";
    }
}; // fim da classe Node

class list{
private:
    Node* m_head{};
    unsigned m_size{};
public:
    // Construtor vazio
    list(){
        m_head=new Node(0,nullptr,nullptr);
        m_head->next=m_head;
        m_head->prev=m_head;
    }
    
    // Função quee retorna se lista esta vazia
    bool empty() const{
        return m_size==0;
    }

    unsigned size() const{
       return m_size; 
    }

    void push_back(const int& val){
        Node* temp=new Node(val,m_head->prev,m_head);
        // acessando o ultimo elemento, mudando o next para o novo auxiliar;
        m_head->prev->next=temp;
        m_head->prev=temp;

        ++m_size;
    }

    void pop_back(){
        if(m_size>0){
            Node* temp=m_head->prev;
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;

            delete temp;

            --m_size;
        }
    }

    // Função que terona uma referencia
    // para o primeiro elemento
    int& front(){
        if(empty()){ // se lista estiver vazia
            throw std::runtime_error("lista vazia");
        }
        else{
            return m_head->next->data;
        }
    }

    const int& front() const{
        if(empty()){ // se lista estiver vazia
            throw std::runtime_error("lista vazia");
        }
        else{
            return m_head->next->data;
        }
    }

    int& back(){
        if(empty()){ // se lista estiver vazia
            throw std::runtime_error("lista vazia");
        }

        return m_head->prev->data;
    }

    const int& back() const{
        if(empty()){ // se lista estiver vazia
            throw std::runtime_error("lista vazia");
        }

        return m_head->prev->data;
    }
    void clear(){
        while(m_head->next!=m_head){
            Node* aux=m_head->next;
            m_head->next=aux->next;
            aux->next->prev=aux->prev;
            delete aux;
        }
        m_size=0;
    }
    ~list(){
        clear();
        delete m_head;
    }
};

#endif