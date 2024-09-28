/*
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 2
* Description : PQHeap assignment
*/

#include "Heap.h"
//
// Created by DELL on 8.03.2024.
//

#include "PQHeap.h"
#include <iostream>
using namespace std;
Heap::Heap() {
    size = 0;
    for (int i = 0; i < size; i++){ // Won't be executed.
        items[i] = Request();
    }
}

Heap::~Heap() {}

bool Heap::isEmpty() const {
    return size == 0;
}

void Heap::heapInsert( const Request& newItem) {
    if(size >= MAX_HEAP){
        cout<<"Heap is full!"<<endl;
        return ;} //heap is full
    else{
        items[size] = newItem;

        // Trickle new item up to its proper position
        int place = size;
        int parent = (place - 1)/2;
        while ( (place > 0) && (items[place].getPriority() > items[parent].getPriority()) ) {
            Request temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = (place - 1)/2;
        }
        ++size;
    }
}
void Heap::heapDelete() {
    if(isEmpty()){return;}
    else{
        items[0] = items[size-1];
        size--;
        heapRebuild(0);
    }
}
void Heap::heapRebuild(int root) {
    int child = 2 * root + 1;    // index of root's left child, if any
    if (child < size) {
        // root is not a leaf so that it has a left child
        int rightChild = child + 1;    // index of a right child, if any
        // If root has right child, find larger child
        if ((rightChild < size) &&
                items[rightChild].isPriorer(items[child]))
            child = rightChild;    // index of larger child

        // If root’s item is smaller than larger child, swap values
        if (items[child].isPriorer(items[root])) {
            Request temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            // transform the new subtree into a heap
            heapRebuild(child);
        }
    }
}
Request* Heap::getItem(const int i) {
    if(i<size){
        return &items[i];
    }
    return nullptr;
}

bool Heap::is_Exist(const int id){
    for (int i  = 0; i < getSize(); i++){
        if (items[i].getID() == id)
            return true;
    }
    return false;
}

int Heap::getSize() {
    return size;
}
void Heap::printHeap(){
    if (isEmpty()){
        cout <<" Empty heap\n";
        return;
    }
    cout<<" Current heap [ ";
    for (int i = 0; i < getSize(); i++){
        cout << items[i].getID() << " , ";
    }
    cout<<" ]"<<endl;
}
/*
Request* Heap::getTop(){
    return getItem(0);
}
Request* Heap::getItem(const int i) const{
    if(i<size){
        return items[i];
    }
    return nullptr;
}*/