/**
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 3
* Description : Creatures and Foods
*/
#ifndef HW6_CREATUREMANAGER_H
#define HW6_CREATUREMANAGER_H
#include "Creature.h"
#include "FoodManager.h"
#include <vector>

using namespace std;

class CreatureManager {
private:
    vector<Creature*> c_List;   //Creature pointer List
    bool willTheyFigth(Creature const c1, Creature const c2); //checks distance < 2; if so, return 1
    static bool compareByID(Creature* c1, Creature* c2);
    void GameMove(FoodManager& fm);
    void BestFoodConsume(FoodManager& fm);
    void GameFight();
    void moveToFood(Creature* &Creature, Food* &bestFoodPtr);
public:
    CreatureManager();
    ~CreatureManager();
    void addCreature(Creature* &c);

    void printCreatures();
    void printCreaturesLocations();

    void BigGame(FoodManager& fm);
    bool allDead();
};

#endif //HW6_CREATUREMANAGER_H
