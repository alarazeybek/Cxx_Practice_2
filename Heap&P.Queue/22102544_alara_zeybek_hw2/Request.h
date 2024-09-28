/*
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 2
* Description : PQHeap assignment
*/
#ifndef HW2_SPRING_REQUEST_H
#define HW2_SPRING_REQUEST_H


class Request {
public:
    Request(int id, int priority, int r_time, int p_time);
    Request();
    int getID();
    int getPriority();
    int getRTime();
    int getPTime();
    int getWaitingTime();
    void setWaitingTime(const int t);

    int getRemaining_ptime();
    void processedTime(int processingTime);
    bool isRequestDone();
    void printRequest();

    bool isPriorer(Request r);
private:
    int id;
    int priority;
    int r_time;
    int p_time;
    int remaining_ptime;
    int w_time;

};


#endif //HW2_SPRING_REQUEST_H
