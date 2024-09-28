/**
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 3
* Description : Creatures and Foods
*/

#include "Food.h"

Food::Food(int id, double x, double y, int quality, int spawnTime) : id(id), x(x), y(y), quality(quality),
                                                                     spawnTime(spawnTime) {
    isEaten = 0;
}

bool Food::getisEaten() const {
    return isEaten;
}
void Food::setIsEaten(bool isEaten) {
    Food::isEaten = isEaten;
}
int Food::getId() const {
    return id;
}
double Food::getX() const {
    return x;
}
void Food::setX(double x) {
    Food::x = x;
}
double Food::getY() const {
    return y;
}
void Food::setY(double y) {
    Food::y = y;
}
int Food::getQuality() const {
    return quality;
}
int Food::getSpawnTime() const {
    return spawnTime;
}
