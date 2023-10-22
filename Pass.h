#ifndef PASS_H
#define PASS_H
#include <iostream>

class Pass{
    // classe amigo de pass
    // List pode modificar os atributos
    friend class NodeList;
    friend class iterator_list;
private:
    std::string from;
    std::string startTime;
    std::string endTime;
public:
    // construtpr vazio
    Pass(){}
    // construtor
    Pass(const std::string& city,const std::string& start_time,const std::string& end_time){
        this->from=city;
        startTime=start_time;
        endTime=end_time;
    }

    const std::string& showfrom() const{
        return from;
    }

    const std::string& showStartTime() const{
        return startTime;
    }

    const std::string& showEndTime() const{
        return endTime;
    }

    void from(){
        this->from={};
    }

    void from(const unsigned& newFrom){
        from=newFrom;
    }

    void startTime(){
        this->startTime={};
    }

    void startTime(const std::string& newStartTime){
        startTime=newStartTime;
    }

    void endTime(){
        this->endTime={};
    }

    void endTime(const std::string& newEndTime){
        endTime=newEndTime;
    }

    void erasePass(){
        this->from={};
        this->startTime={};
        this->endTime={};
    }
};

#endif