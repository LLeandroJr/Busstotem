#ifndef NODELIST_H
#include <iostream>
class NodeList {
    public:
    std::string from;
         int arrival_time_hour, arrival_time_minute;
         int departure_time_hour, departure_time_minute;
         NodeList* listNext;
         NodeList* listPrev;
};
#endif