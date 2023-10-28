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

    const std::string& showFrom() const{
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

    void resetFrom(){
        this->from={};
    }

    void newFrom(const unsigned& new_From){
        from=new_From;
    }

    void resetStartTimeHour(){
        this->startTimeHour={};
    }

    void newStartTimeHour(const int& new_StartTimeHour){
        startTimeHour=new_StartTimeHour;
    }

    void resetStartTimeMin(){
        this->startTimeMin={};
    }

    void newStartTimeMin(const int& new_StartTimeMin){
        startTimeMin=new_StartTimeMin;
    }

    void resetEndTimeHour(){
        this->endTimeHour={};
    }

    void newEndTimeHour(const int& new_EndTimeHour){
        endTimeHour=new_EndTimeHour;
    }

    void resetEndTimeMin(){
        this->endTimeMin={};
    }

    void newEndTimeMin(const int& new_EndTimeMin){
        endTimeMin=new_EndTimeMin;
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