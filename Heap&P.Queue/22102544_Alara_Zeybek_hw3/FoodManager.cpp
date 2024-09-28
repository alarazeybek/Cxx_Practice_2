/**
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 3
* Description : Creatures and Foods
*/
#include "FoodManager.h"
#include <iostream>
using namespace std;

FoodManager::FoodManager(){
    f_List_All = new PriorityQueue(true);
    f_List_inGame = new PriorityQueue(false);
}
FoodManager::~FoodManager(){
    for(int k = 0; k<f_List_All->getSize();k++){
        delete f_List_All->getItem(k);
    }
    delete f_List_All;
    delete f_List_inGame;
}
void FoodManager::createAllFoodQueue(Food* &f){
    f_List_All->heapInsert(f);
}

void FoodManager::addFoodInGame(int time) {
    int tempSize = f_List_All->getSize();
    for (int k = 0; k < tempSize; k++) {
        if (f_List_All->getItem(k)->getSpawnTime() <= time && f_List_All->getItem(k)->getisEaten()==0) {
            f_List_inGame->heapInsert(f_List_All->getItem(k));
        }
    }
}
void FoodManager::clearFoodInGame(){
    f_List_inGame->setSize(0);
}
Food* FoodManager::giveBestQuality(){
    if(f_List_inGame->isEmpty()){
        return nullptr;
    }
    return f_List_inGame->getTop();
}
void FoodManager::changeBestQuality(){
    if(f_List_inGame->isEmpty()){
        return;
    }
    f_List_inGame->getTop()->setIsEaten(true);
    f_List_inGame->heapDelete();
}
void FoodManager::printAllFood(){
    PriorityQueue temp = f_List_All;
    cout<<"All foods in the archive:\n";
    int k = 0;
    while (k< f_List_All->getSize()) {
        cout<< "Id  "<< f_List_All->getItem(k)->getId()<<endl;
        cout<< "X  "<< f_List_All->getItem(k)->getX()<<endl;
        cout<< "Y  "<<f_List_All->getItem(k)->getY()<<endl;
        cout<< "Quality  "<< f_List_All->getItem(k)->getQuality()<<endl;
        cout<< "Spawn time  "<< f_List_All->getItem(k)->getSpawnTime()<<endl;
        cout<<"Is eaten?    "<< f_List_All->getItem(k)->getisEaten() <<endl;
        cout<<"-----------------------"<<endl;
        k++;
    }
}


