/*
 * Alara Zeybek
 * Sec 3
 * 22102544
 * CS202 hw 4
 * Input example: ./a.out "S Apple\nS Chips\nS Cheese\nS Crackers\nC Apple Chips\nC Cheese Crackers\nC Crackers Apple\nC Crackers Chips\nL Crackers\nL Chips\nD Crackers Cheese\nL Crackers\nQ Apple Chips\nQ Cheese Crackers\nX"
 */
#include "alara_zeybek_22102544_SnackHashing.h"
#include "alara_zeybek_22102544_Snack.h"
#include <iostream>
using namespace std;

SnackHashing::SnackHashing() {
    bucket = new LinkedList[tablesize];
}

SnackHashing::~SnackHashing() {
    delete[] bucket;
}

int SnackHashing::hash(string s) const {
    int index = 0;
    for (int i = 0; i < s.length(); i++)
    {
        index += ((int)s[i]);
    }
    return index%tablesize;
}

bool SnackHashing::addNewSnack(string s) {
    int index = hash(s);
    return bucket[index].addNode(s);
}

bool SnackHashing::deleteNewSnack(string s) {
    int i = hash(s);
    return bucket[i].deleteNode(s);
}
Snack* SnackHashing::findSnackInTable(string s){
    int index = hash(s);
    Node* temp = bucket[index].searchNode(s);
    if(temp == nullptr){
        return nullptr;
    }
    return temp->item;
}

void SnackHashing::printSnackTable() {
    int index = 0;
    for (int i = 0; i < tablesize; i++)
    {
        cout<<"Index "<< i <<" element: " <<endl;
        bucket[i].printLinkedList();
    }
}
void SnackHashing::printAccofSpecificSnack(string s){
    //cout<<"Accompaniments of "<<s<<": ";
    Snack* temp = findSnackInTable(s);
    temp->getGivenWith()->printLinkedList();
}
