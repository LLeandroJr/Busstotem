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
    Data():ID(),company("undefined"),to("undefined"){}
    // Construtor que atribui ao objeto da classe Data.
    // Data(const unsigned int& <ID>,const std::string& <company>,const std::string& <to>)
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
    void resetID(){
        this->ID={};
    }
    
    // Função sem parâmetros
    // Função que atribui newID a class Data
    // Complexidade: O(1)
    void newID(const unsigned& new_ID){
        ID=new_ID;
    }
    
    // Função sem parâmetros
    // Função que torna vazio o atributo company da class Data
    // Complexidade: O(1)
    void resetCompany(){
        this->company={};
    }

    // Função sem parâmetros
    // Função que atribui newCompany a class Data
    // Complexidade: O(1)
    void newCompany(const std::string& new_company){
        company=new_company;
    }

    // Função sem parâmetros
    // Função que torna vazio o atributo company da class Data
    // Complexidade: O(1)
    void resetTo(){
        this->to={};
    }

    // Função sem parâmetros
    // Função que atribui newTo a class Data
    // Complexidade: O(1)
    void newTo(const std::string& new_to){
        to=new_to;
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
