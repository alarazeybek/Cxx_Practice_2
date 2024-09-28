/**
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 3
* Description : Creatures and Foods
*/

#ifndef HW6_FOOD_H
#define HW6_FOOD_H

class Food {
private:
    int id;
    double x;
    double y;
    int quality;
    int spawnTime;

    bool isEaten;

public:
    Food(int id,double x,double y,int quality, int spawnTime);


//----------GETTERS & SETTERS---------------------------------
    int getId() const;
    void setId(int id);
    double getX() const;
    void setX(double x);
    double getY() const;
    void setY(double y);
    int getQuality() const;
    void setQuality(int quality);
    int getSpawnTime() const;
    void setSpawnTime(double spawnTime);
    bool getisEaten() const;
    void setIsEaten(bool isEaten);

};


#endif //HW6_FOOD_H
