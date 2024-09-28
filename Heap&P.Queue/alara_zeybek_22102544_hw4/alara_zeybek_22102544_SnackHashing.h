/*
 * Alara Zeybek
 * Sec 3
 * 22102544
 * CS202 hw 4
 * Input example: ./a.out "S Apple\nS Chips\nS Cheese\nS Crackers\nC Apple Chips\nC Cheese Crackers\nC Crackers Apple\nC Crackers Chips\nL Crackers\nL Chips\nD Crackers Cheese\nL Crackers\nQ Apple Chips\nQ Cheese Crackers\nX"
 */
#ifndef SNACKHASHING_H
#define SNACKHASHING_H
#include "alara_zeybek_22102544_Snack.h"

class SnackHashing {
public:
    SnackHashing();
    ~SnackHashing();
    bool addNewSnack(string s);
    bool deleteNewSnack(string s);
    Snack* findSnackInTable(string s);
    void printSnackTable();

    void printAccofSpecificSnack(string s);
private:
    const int tablesize = 11;
    LinkedList* bucket; //each index of table will be Snack linked list bcs of seperate chaining
    int hash(string s) const;
};

#endif
