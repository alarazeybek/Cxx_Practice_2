/**
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 3
* Description : Creatures and Foods
*/
#include "Creature.h"
#include <iostream>
using namespace std;

Creature::Creature(int id,double x,double y,int health){
    Creature::id = id;
    Creature::x = x;
    Creature::y = y;
    Creature::health = health;
    Creature::isDead = 0;
    //willMove = 1;
}
void Creature::healthDecrease(){
    if(isDead){
        return;
    }
    if(getHealth() - 1 <= 0){
        this->isDead = true;
        return;
    }
    health--;
}
void Creature::healthIncrease(){
    if(isDead){
        return;
    }
    health++;
}
//----------------------GETTERS & SETTERS---------------------------------------
/*bool Creature::getWillMove() const {
    return willMove;
}
void Creature::setWillMove(bool willMove) {
    Creature::willMove = willMove;
}*/
int Creature::getId() const {
    return id;
}
double Creature::getX() const {
    return x;
}
double Creature::getY() const {
    return y;
}
int Creature::getHealth() const {
    return health;
}
bool Creature::getisDead() const {
    return isDead;
}
void Creature::setisDeadTrue() {
    isDead = 1;
}
void Creature::setX(double x) {
    Creature::x = x;
}
void Creature::setY(double y) {
    Creature::y = y;
}
void Creature::setHealth(int health) {
    Creature::health = health;
}

