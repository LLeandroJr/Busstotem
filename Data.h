#ifndef DATA_H
#define DATA_H
#include <iostream>

// Classe que contém os atributos do tipo unsigned int, string e string.
// Respectivamente:
// ID: número de identificação da linha.
// company: companhia.
// to: destino.
class Data{
    friend class Node;
    friend class iterator_forwardList;
private:
    unsigned ID; // Número de identificação da linha.
    std::string company; // Companhia.
    std::string to; // Destino.
public:
    // Construtor vazio.
    Data(){}
    // Construtor que atribui ao objeto da classe Data.
    // Data(const unsined int& <ID>,const std::string& <company>,const std::string& <to>)
    Data(const unsigned int& ID,const std::string& company, const std::string& to){
        this->ID=ID;
        this->company=company;
        this->to=to;
    }

    // Função sem parâmetros
    // Retorna o atributo ID da class Data
    // Complexidade: O(1)
    const unsigned& showID() const{
        return ID;
    }

    // Função sem parâmetros
    // Retorna o atributo company da class Data
    // Complexidade: O(1)
    const std::string& showCompany() const{
        return company;
    }

    // Função sem parâmetros
    // Retorna o atributo to da class Data
    // Complexidade: O(1)
    const std::string& showTo() const{
        return to;
    }

    // Função sem parâmetros
    // Função que torna vazio o atributo ID da class Data
    // Complexidade: O(1)
    void ID(){
        this->ID={};
    }
    
    // Função sem parâmetros
    // Função que atribui newID a class Data
    // Complexidade: O(1)
    void ID(const unsigned& newID){
        ID=newID;
    }
    
    // Função sem parâmetros
    // Função que torna vazio o atributo company da class Data
    // Complexidade: O(1)
    void company(){
        this->company={};
    }

    // Função sem parâmetros
    // Função que atribui newCompany a class Data
    // Complexidade: O(1)
    void company(const std::string& newCompany){
        company=newCompany;
    }

    // Função sem parâmetros
    // Função que torna vazio o atributo company da class Data
    // Complexidade: O(1)
    void to(){
        this->company={};
    }

    // Função sem parâmetros
    // Função que atribui newTo a class Data
    // Complexidade: O(1)
    void to(const std::string& newTo){
        to=newTo;
    }

    // Função sem parâmetros
    // Função que torna vazio todos os atributos da class Data
    // Complexidade: O(1)
    void eraseData(){
        this->ID={};
        this->company={};
        this->to={};
    }
};

#endif
