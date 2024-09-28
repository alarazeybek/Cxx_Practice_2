/*
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 2
* Description : PQHeap assignment
*/
#include <iostream>
#include <fstream>
#include <string>
#include "Scheduling.h"
#include "PQHeap.h"

using namespace std;


int main(int argc, char* argv[]) {
    ifstream file;
    file.open (argv[1]);
    if (!file.is_open()) return -1;

    string word;
    getline (file, word);
    int request_size = stoi(word);
    //cout<< request_size <<endl;
    Request* program_requests = new Request[request_size];

    int counter = 0, index = 0;

    int id, priority, r_time, p_time;
    while (file >> word){
        int w = stoi(word);
        switch (counter%4){
            case 0:
                id = w;
                break;
            case 1:
                priority = w;
                break;
            case 2:
                r_time = w;
                break;
            case 3:
                p_time = w;
                program_requests[index++] = Request(id,priority,r_time,p_time);
                break;
        }
        counter++;
    }
    int comp_num = 0;
    double requested_avgtime = std::atof(argv[2]);
    double avgtime = requested_avgtime + 1;
    string printer = "";
    while(avgtime > requested_avgtime){
        comp_num++;
        Scheduling s(program_requests,request_size,comp_num);
        avgtime = s.getAverageWaitingTime();
        printer = s.printStatement;
    }
    cout<<"Minimum number of computers required: "<<comp_num<<"\n"<<endl;
    cout<<"Simulation with "<<comp_num << " computers:\n"<<endl;
    cout<<printer<<endl;
    cout<<"Average waiting time: " << avgtime<< " ms\n";

    delete[] program_requests;
    return 0;
}
