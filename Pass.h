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
    int startTimeHour,startTimeMin;
    int endTimeHour,endTimeMin;
public:
    // construtor vazio
    Pass(){}
    // construtor
    // Pass(const std::string& <city>,const int& <start_time_hour>,const int& <start_time_min>,const int& <end_time_hour>,const int& <end_time_min>){
    Pass(const std::string& city,const int& start_time_hour,const int& start_time_min,const int& end_time_hour,const int& end_time_min){
        this->from=city;
        startTimeHour=start_time_hour;
        startTimeMin=start_time_min;
        endTimeHour=end_time_hour;
        endTimeMin=end_time_min;
    }

    const std::string& showfrom() const{
        return from;
    }

    const int& showStartTimeHour() const{
        return startTimeHour;
    }

    const int& showStartTimeMin() const{
        return startTimeMin;
    }

    const int& showEndTimeHour() const{
        return endTimeHour;
    }

    const int& showEndTimeMin() const{
        return endTimeMin;
    }

    void from(){
        this->from={};
    }

    void from(const unsigned& newFrom){
        from=newFrom;
    }

    void startTimeHour(){
        this->startTimeHour={};
    }

    void startTimeMin(){
        this->startTimeMin={};
    }

    void startTimeHour(const int& newStartTimeHour){
        startTimeHour=newStartTimeHour;
    }

    void startTimeMin(const int& newStartTimeMin){
        startTimeMin=newStartTimeMin;
    }

    void endTimeHour(){
        this->endTimeHour={};
    }

    void endTimeHour(const int& newEndTimeHour){
        endTimeHour=newEndTimeHour;
    }

    void endTimeMin(){
        this->endTimeMin={};
    }

    void endTimeMin(const int& newEndTimeMin){
        endTimeMin=newEndTimeMin;
    }

    void erasePass(){
        this->from={};
        this->startTimeHour={};
        this->startTimeMin={};
        this->endTimeHour={};
        this->endTimeMin={};
    }
};

#endif