/*
 * Alara Zeybek
 * Sec 3
 * 22102544
 * CS202 hw 4
 * Input example: ./a.out "S Apple\nS Chips\nS Cheese\nS Crackers\nC Apple Chips\nC Cheese Crackers\nC Crackers Apple\nC Crackers Chips\nL Crackers\nL Chips\nD Crackers Cheese\nL Crackers\nQ Apple Chips\nQ Cheese Crackers\nX"
 */
#ifndef SNACK_H
#define SNACK_H
#include <iostream>
using namespace std;
struct Node;
class LinkedList;
class Snack{
private:
    string name;
    LinkedList* givenWith;
public:
    Snack(string str);
    Snack(Snack &t);
    ~Snack();
    LinkedList* getGivenWith();
    Snack* addAccompanied(string s);
    bool deleteAccompanied(string s);
    string getName();
    bool operator==(const Snack &rhs) const;
};

//typedef Snack ItemType;
struct Node{
    Snack* item;
    Node* next;
    Node(Snack* a){
        next = nullptr;
        item = a ;
    }
    Node(Node &a){
        next = a.next;
        item = a.item ;
    }
    ~Node(){
        next = nullptr;
        delete item;
    }
};
class LinkedList {
private:
    Node* root;
public:
    LinkedList();
    LinkedList(LinkedList& l);
    ~LinkedList();
    bool addNode(string i);    //ItemType verince başka class ta Itemtype int diye görnüyor
    bool deleteNode(string i); //ItemType verince başka class ta Itemtype int diye görnüyor
    Node* searchNode(string i);
    bool isEmpty();
    Snack* getRootItem();
    void printLinkedList();
};
#endif
