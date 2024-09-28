/**
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 3
* Description : Creatures and Foods
*/

#include "PriorityQueue.h"


PriorityQueue::PriorityQueue(const bool isThisAllFoodQueue) {
    size = 0;
    allFoodQueue = isThisAllFoodQueue;
}

PriorityQueue::~PriorityQueue() {}

bool PriorityQueue::isEmpty() {
    return size == 0;
}

bool PriorityQueue::heapInsert( Food* newItem) {
    if(size >= 35){return false;} //heap is full
    else{
        items[size] = newItem;
        int firstInsertedPlace = size;
        int parentIndex = (firstInsertedPlace-1)/2;
        if(allFoodQueue) {
            while (parentIndex >= 0 && items[firstInsertedPlace]->getSpawnTime() < items[parentIndex]->getSpawnTime()) {
                //-------updating array location-elements
                Food* temp = items[firstInsertedPlace];
                items[firstInsertedPlace] = items[parentIndex];
                items[parentIndex] = temp;
                //-------going one step upward
                firstInsertedPlace = parentIndex;
                parentIndex = (firstInsertedPlace - 1) / 2;
            }
        }
        else{
            while (parentIndex >= 0 && items[firstInsertedPlace]->getQuality() > items[parentIndex]->getQuality()) {
                //-------updating array location-elements
                Food* temp = items[firstInsertedPlace];
                items[firstInsertedPlace] = items[parentIndex];
                items[parentIndex] = temp;
                //-------going one step upward
                firstInsertedPlace = parentIndex;
                parentIndex = (firstInsertedPlace - 1) / 2;
            }
        }
        size++;
        return true;
    }
}
void PriorityQueue::heapDelete() {
    if(isEmpty()){return;}
    else{
        items[0] = items[size-1];
        size--;
        heapRebuild(0);
    }
}
void PriorityQueue::heapRebuild(int root) {
    int child = 2*root + 1;
    if(child < size){
        int right = child+1;
        if(allFoodQueue){    // minHeap
            if(right< size && items[child]->getSpawnTime() > items[right]->getSpawnTime()){
                child = right;
            }
            if(items[root]->getSpawnTime() > items[child]->getSpawnTime()){
                Food* temp = items[child];
                items[child] = items[root];
                items[root] = temp;
                heapRebuild(child);
            }
        }
        else{           //maxHEap
            if(right< size && items[child]->getQuality() < items[right]->getQuality()){
                child = right;
            }
            if(items[root]->getQuality() < items[child]->getQuality()){
                Food* temp = items[child];
                items[child] = items[root];
                items[root] = temp;
                heapRebuild(child);
            }
        }
    }
}
int PriorityQueue::getSize() const {
    return size;
}

void PriorityQueue::setSize(int size) {
    PriorityQueue::size = size;
}

Food* PriorityQueue::getTop(){
    return items[0];
}
Food* PriorityQueue::getItem(const int i) const{
    if(i<size){
        return items[i];
    }
    return nullptr;
}