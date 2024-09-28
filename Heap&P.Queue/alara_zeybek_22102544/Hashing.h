//
// Created by DELL on 25.04.2024.
//

#ifndef CS202_HW3_HASHING_H
#define CS202_HW3_HASHING_H
#include <string.h>
#include <iostream>

using namespace std;

//typedef Snack ItemType;
struct Node{
    string item;
    Node* next;
    Node(string a){
        next = nullptr;
        item = a ;
    }
    Node(Node &a){
        next = a.next;
        item = a.item ;
    }
    ~Node(){
        next = nullptr;
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
    Node* getRootItem();
    void printLinkedList();
};

class Hashing {
public:
    Hashing();
    ~Hashing();
    bool addNewItem(string s);
    bool deleteNewItem(string s);
    string findItemInTable(string s);
    void printTable();

    void printAccofSpecificSnack(string s);
    string f(string prefix, string suffix);
    void WordFilter(string* words, int size);
    int searchCollision(string* words, int size);
private:
    const int tablesize = 1000;
    LinkedList* bucket; //each index of table will be Snack linked list bcs of seperate chaining
    int hash(string s) const;
};



#endif //CS202_HW3_HASHING_H
