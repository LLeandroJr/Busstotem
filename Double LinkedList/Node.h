#ifndef NODE_H
#define NODE_H
#include <iostream>
class Node {
    public:
    std::string from;
         int arrival_time_hour, arrival_time_minute;
         int departure_time_hour, departure_time_minute;
         Node* next;
         Node* prev;
};
#endif