/*
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 2
* Description : PQHeap assignment
*/

#include <iostream>
#include <iomanip>
#include "Scheduling.h"

using namespace std;

Scheduling::Scheduling(Request *arr, int program_request_num, int num_of_computers) {
    printStatement = "";
    queue = PQHeap();
    total_waiting_time = 0;
    finish_time = 1;
    log_file_arr = arr;
    request_num = program_request_num;
    computer_num = num_of_computers;
    computer_arr = new Computer[num_of_computers]; // dynamic olmayan allocation
    for (int i = 0; i < num_of_computers; i++){
        computer_arr[i].id = i;
        computer_arr[i].is_available = true;
    }
    Process();
}

Scheduling::~Scheduling() {
    //delete[] computer_arr;
    computer_arr = nullptr;
}

double Scheduling::getAverageWaitingTime() {
    double avg = static_cast<double>(total_waiting_time) / request_num;
    std::cout << std::fixed << std::setprecision(2);
    return avg;
}

void Scheduling::Process(){
    int time = 0;
    int log_file_index = 0;
    int processed_request = 0;
    while (processed_request < request_num){
        Request *curr = nullptr;
       do{
           if (processed_request >= request_num){
               break;
           }
           checkedFinishWork(time); // Free the computers that finish their request.
           curr = &log_file_arr[log_file_index];
           if (curr == nullptr){
               break;
           }
           if ( curr->getRTime() == time && log_file_index < request_num){
               queue.PQInsert(*curr);
               log_file_index++; // move to the next request
               continue; // Do not increment time, bcs next request may come at the same time as the previous one.
           }
           if (!queue.isEmpty()){
               Computer *availableC = getAvailableComputer(); // Get an available computer.
               if (availableC != nullptr){
                   processed_request++;
                   availableC->is_available = false;
                   availableC->processed_request = *queue.getTop();
                   int waiting_time = time - availableC->processed_request.getRTime();
                   availableC->processed_request.setWaitingTime(waiting_time);
                   total_waiting_time += waiting_time;
                   queue.PQDelete(); // Request is assigned no need to wait in the waiting queue.
                   printStatement +=  "Computer " + to_string(availableC->id) + " takes request " +
                           to_string(availableC->processed_request.getID()) +
                   " at ms " + to_string(time) + " (wait: " + to_string(waiting_time) + " ms)\n";
                   continue;
               }
           }
           time++;
       }while (curr != nullptr && curr->getRTime() >= time);
    }
}

void Scheduling::checkedFinishWork(int time){
    for (int i = 0; i < computer_num; i++){
        Computer c = computer_arr[i];
        if (!c.is_available) {
            if ( c.processed_request.getPTime() +
                c.processed_request.getWaitingTime() >= time - c.processed_request.getRTime() ) {
                continue;
            }
            computer_arr[i].is_available = true;
        }
    }
}

Computer* Scheduling::getAvailableComputer(){
    for (int i = 0; i < computer_num; i++){ // Starting from the lowest id
        if (computer_arr[i].is_available)
            return &computer_arr[i];
    }
    return nullptr;
}
