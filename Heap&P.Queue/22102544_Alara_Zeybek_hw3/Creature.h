/**
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 3
* Description : Creatures and Foods
*/

#ifndef HW6_CREATURE_H
#define HW6_CREATURE_H


class Creature {
private:
    int id;
    double x;
    double y;
    int health;

    bool isDead;
    //bool willMove;


public:
    Creature(int id,double x,double y,int health);
//--------------------SETTERS & GETTERS--------------
    int getId() const;
    double getX() const;
    double getY() const;
    int getHealth() const;
    void setX(double x);
    void setY(double y);
    bool getisDead() const;
    void setisDeadTrue();
    void setHealth(int health);
    void healthDecrease();
    void healthIncrease();

    /*bool getWillMove() const;
    void setWillMove(bool willMove);*/

};


#endif //HW6_CREATURE_H
