/*
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 2
* Description : PQHeap assignment
*/
#include <iostream>

#include "Request.h"
Request::Request(int rid, int rpriority, int rr_time, int rp_time){
    id = rid;
    priority = rpriority;
    r_time = rr_time;
    p_time = rp_time;
    remaining_ptime = p_time;
    w_time = 0;
}
Request::Request(){}

int Request::getID(){return id;}

int Request::getPriority(){return priority;}

int Request::getRTime(){return r_time;}

int Request::getPTime(){return p_time;}

int Request::getWaitingTime() {return w_time;}

void Request::setWaitingTime(const int t){
    w_time = t;
}

int Request::getRemaining_ptime(){return remaining_ptime;}


void Request::processedTime(int processingTime){
    remaining_ptime -= processingTime;
    w_time += processingTime;
}

bool Request::isRequestDone(){
    return remaining_ptime <= 0;
}


bool Request::isPriorer(Request r){
    if (r.getPriority() == priority) {
        if (r_time == r.getRTime()) {
            return p_time < r.getPTime();
        }
        return r_time < r.getRTime();
    }
    return priority > r.getPriority();
}

void Request::printRequest(){
    std::cout << "Request with id "<<id<<" priority "<<priority<<" r-time "<<r_time<<" p-time "<<p_time<< std::endl;
}