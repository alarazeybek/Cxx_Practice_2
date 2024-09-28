/*
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 2
* Description : PQHeap assignment
*/

#ifndef HW2_SPRING_SCHEDULING_H
#define HW2_SPRING_SCHEDULING_H
#include "PQHeap.h"

struct Computer{
    int id;
    Request processed_request;
    bool is_available;
};

class Scheduling {
public:
    Scheduling(Request *arr, int program_request_num, int num_of_computers);
    ~Scheduling();

    double getAverageWaitingTime();
    std::string printStatement;

protected:
    void Process();
    void checkedFinishWork(int time);
    Computer* getAvailableComputer(); // If no available computer, returns nullptr
private:
    PQHeap queue;
    Request* log_file_arr = nullptr;
    Computer* computer_arr = nullptr;
    int computer_num;
    int request_num;
    int total_waiting_time;
    int finish_time;
};


#endif //HW2_SPRING_SCHEDULING_H
