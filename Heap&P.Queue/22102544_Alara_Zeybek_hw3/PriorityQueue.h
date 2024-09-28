/**
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 3
* Description : Creatures and Foods
*/

#ifndef HW6_GAMESIMCS202_PRIORITYQUEUE_H
#define HW6_GAMESIMCS202_PRIORITYQUEUE_H
#include "Food.h"

class PriorityQueue {
public:
    PriorityQueue(const bool isThisAllFoodQueue);
    ~PriorityQueue();

    bool isEmpty();
    bool heapInsert(Food* newItem);
    void heapDelete();

    int getSize() const;
    Food* getTop();
    Food* getItem(const int i) const;

    void setSize(int size);
    // root item deleted itemtype olarak initilize ediliyor o yüzden parametre

protected:
    void heapRebuild(int root);
private:
    bool allFoodQueue;
    int size;
    Food* items[35];
};


#endif //HW6_GAMESIMCS202_PRIORITYQUEUE_H
