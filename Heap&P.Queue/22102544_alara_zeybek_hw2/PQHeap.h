/*
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 2
* Description : PQHeap assignment
*/

#include "Request.h"
#include "Heap.h"
#ifndef HW2_SPRING_PQHEAP_H
#define HW2_SPRING_PQHEAP_H
class PQHeap {

public:
    PQHeap();
    ~PQHeap();

    bool isEmpty();
    bool PQInsert(Request& newItem);
    void PQDelete();

    void printHeap();

    //int getSize();
    Request* getTop();
    bool isExist(int r_id);

private:
   Heap h;
};


#endif //HW2_SPRING_PQHEAP_H
