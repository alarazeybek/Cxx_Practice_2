/**
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 3
* Description : Creatures and Foods
*/

#include "CreatureManager.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

CreatureManager::CreatureManager(){
}
CreatureManager::~CreatureManager(){
    vector<Creature*>::iterator it;
    for(it=c_List.begin(); it != c_List.end(); it++){
         delete *it;
         *it = nullptr;
    }
    c_List.clear();
   // c_List.shrink_to_fit(); //HEAP ERROR ÇIKARSA DENE
}
void CreatureManager::addCreature(Creature* &c){
    c_List.push_back(c);
    sort(c_List.begin(),c_List.end(),compareByID );
}
//---------------HELPER PRIVATE METHODS---------------------------
bool CreatureManager::willTheyFigth(Creature const c1, Creature const c2){
    double x_diff = c1.getX()-c2.getX();
    double y_diff = c1.getY()-c2.getY();
    double a = x_diff*x_diff + y_diff*y_diff;
    return a < 4.0 ;   //squareroot of a < 2 && c1.getHealth()>=c2.getHealth()
}
bool CreatureManager::compareByID(Creature* c1, Creature* c2){
    return c1->getId() < c2->getId();
}
//---------- TO STRING-------------------------------
void CreatureManager::printCreatures(){
    vector<Creature*>::iterator it;
    cout<< "Here is the creatures in the game:\n";
    for(it=c_List.begin(); it != c_List.end(); it++){
        cout<<"ID   "<< (*it)->getId()<<endl;
        cout<<"X    "<< (*it)->getX()<<endl;
        cout<<"Y    "<< (*it)->getY()<<endl;
        cout<<"Health    "<< (*it)->getHealth()<<endl;
        cout<<"Is dead?    "<< (*it)->getisDead()<<endl;
        cout<<"-----------------------"<<endl;
    }
}
void CreatureManager::printCreaturesLocations(){
    vector<Creature*>::iterator it;
    for(it=c_List.begin(); it != c_List.end(); it++){
        cout<<"Creature "<< (*it)->getId();
        cout <<": " << std::fixed << std::setprecision(2) << (*it)->getX()<<", "<< (*it)->getY()<<endl;
    }
}
//------------------Helper Methods------------------------------
void CreatureManager::GameFight(){
    vector<Creature*>::iterator it;
    vector<Creature*>::iterator it2;
    for(it=c_List.begin(); it != c_List.end(); it++) {
        for (it2 = it + 1; it2 != c_List.end(); it2++) {   // it is an iterator
            if ((*it)->getisDead() || (*it2)->getisDead()) {
                continue;
            }
            bool do_it = willTheyFigth(**(it), **(it2));
            if (do_it) { // it = küçük id, it2 = büyük id
                int i = (*it)->getHealth() - (*it2)->getHealth();
                if (i >= 0) {
                    (*it2)->setHealth(0);
                    (*it2)->setisDeadTrue();
                } else {
                    (*it)->setHealth(0);
                    (*it)->setisDeadTrue();
                }
            }
        }
    }
}
void CreatureManager::BestFoodConsume(FoodManager& fm){
    vector<Creature*>::iterator it;
    for(it=c_List.begin(); it != c_List.end(); it++) {
        if(fm.f_List_inGame->isEmpty() || (*it)->getisDead()){
            continue;
        }
        else{
            Food* best = fm.giveBestQuality();
            double dist = sqrt((((*it)->getX() - best->getX()) * ((*it)->getX() - best->getX())) + (((*it)->getY() - best->getY()) * ((*it)->getY() - best->getY())));
            if( dist < 1){
                (*it)->setHealth((*it)->getHealth()+best->getQuality());
                fm.changeBestQuality();
            }
        }
    }
}
void CreatureManager::GameMove(FoodManager& fm){
    vector<Creature*>::iterator it;
    for(it=c_List.begin(); it != c_List.end(); it++) {
        if(fm.f_List_inGame->isEmpty() || (*it)->getisDead()){
            continue;
        }
        else{
            Food* best = fm.giveBestQuality();
            moveToFood((*it),best);
        }
    }
}
void CreatureManager::moveToFood(Creature* &Creature, Food* &bestFoodPtr) {
    if(Creature->getisDead()){
        return;
    }
    double dx = bestFoodPtr->getX() - Creature->getX();
    double dy = bestFoodPtr->getY() - Creature->getY();
    double dist = sqrt(pow(bestFoodPtr->getX() - Creature->getX(), 2) + pow(bestFoodPtr->getY() - Creature->getY(), 2));
    double max_dist = (Creature->getHealth() > 10) ? 10 / static_cast<double>((Creature->getHealth())) : 1;
    double sc = max_dist / dist;
    double n_x = static_cast<double>(Creature->getX()) + static_cast<double>(dx * sc);
    double n_y = static_cast<double>(Creature->getY()) + static_cast<double>(dy * sc);
    Creature->setX(n_x);
    Creature->setY(n_y);
}
void CreatureManager::BigGame(FoodManager& fm){
    GameFight();
    BestFoodConsume(fm);
    GameMove(fm);
    for(auto& c: c_List){
        if(!c->getisDead())
            c->healthDecrease();
    }
}
bool CreatureManager::allDead() {
    for(auto c: c_List){
        if(!c->getisDead()){
            return false;
        }
    }
    return true;
}