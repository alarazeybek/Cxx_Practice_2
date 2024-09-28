/**
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 3
* Description : Creatures and Foods
*/
#ifndef HW6_FOODMANAGER_H
#define HW6_FOODMANAGER_H
#include <queue>
#include "Food.h"
#include "PriorityQueue.h"
using namespace std;

struct MyCompare {
    bool operator()(const Food* a, const Food* b) const {
        return a->getSpawnTime() > b->getSpawnTime(); // return true if a has higher priority than b
    }
};
struct MyCompare2 {
    bool operator()(Food *a, const Food* b) const {
        return a->getQuality() < b->getQuality(); // return true if a has higher priority than b
    }
};
class FoodManager {
public:
    FoodManager();
    ~FoodManager();
    //priority_queue<Food*, vector<Food*>, MyCompare> f_List_All;
    PriorityQueue* f_List_All;
    //priority_queue<Food*, vector<Food*>, MyCompare2> f_List_inGame;
    PriorityQueue* f_List_inGame;

    void createAllFoodQueue(Food* &f);
    void addFoodInGame(int time);
    void clearFoodInGame();

    Food* giveBestQuality();
    void changeBestQuality();
   // Food* findFoodById(int const id);

    //void printInGameFood();
    void printAllFood();
};

#endif //HW6_FOODMANAGER_H