/*
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 2
* Description : PQHeap assignment
*/

#include "PQHeap.h"

PQHeap::PQHeap() {
}

PQHeap::~PQHeap() {}

bool PQHeap::isEmpty() {
    return h.isEmpty();
}

bool PQHeap::PQInsert( Request& newItem) {
    Request* old_root = getTop();
    h.heapInsert(newItem);
    Request* new_root = getTop();
    if (old_root == new_root ){
        return true;
    }
    return false;
}
void PQHeap::PQDelete() {
    h.heapDelete();
}
Request* PQHeap::getTop(){
    return h.getItem(0);
}


bool PQHeap::isExist(int r_id){
    return h.is_Exist(r_id);
}

void PQHeap::printHeap(){
    h.printHeap();
}
/*
int PQHeap::getSize(){
    return h.getSize();
}*/