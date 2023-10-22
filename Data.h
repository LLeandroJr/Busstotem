#ifndef DATA_H
#define DATA_H
#include <iostream>

class Data{
    friend class Node;
    friend class iterator;
private:
    unsigned ID;
    std::string company;
    std::string to;
public:
    // construtor vazio
    Data(){}
    // construtor
    Data(const unsigned int& ID,const std::string& company, const std::string& to){
        this->ID=ID;
        this->company=company;
        this->to=to;
    }

    const unsigned& showID() const{
        return ID;
    }

    const std::string& showCompany() const{
        return company;
    }

    const std::string& showTo() const{
        return to;
    }

    void ID(){
        this->ID={};
    }

    void ID(const unsigned& newID){
        ID=newID;
    }

    void company(){
        this->company={};
    }

    void company(const std::string& newCompany){
        company=newCompany;
    }

    void to(){
        this->company={};
    }

    void to(const std::string& newTo){
        to=newTo;
    }

    void eraseData(){
        this->ID={};
        this->company={};
        this->to={};
    }
};

#endif
