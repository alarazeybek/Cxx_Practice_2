/*
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 2
* Description : PQHeap assignment
*/

#ifndef HW2_SPRING_HEAP_H
#define HW2_SPRING_HEAP_H
#include "Request.h"

const int MAX_HEAP = 100; //MAX initiliazed et

class Heap {
public:
    Heap();
    ~Heap();
    bool isEmpty() const;
    void heapInsert(const Request& newItem);
    void heapDelete(/*HeapItemType& rootItem*/);
    int getSize();
    Request* getItem(const int i);
    bool is_Exist(const int id);

    void printHeap();
protected:
    void heapRebuild(int root);
private:
    Request items[MAX_HEAP];	// array of heap items
    int          size;            	// number of heap items
};

#endif //HW2_SPRING_HEAP_H
