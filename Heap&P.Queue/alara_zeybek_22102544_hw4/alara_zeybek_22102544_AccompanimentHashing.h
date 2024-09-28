/*
 * Alara Zeybek
 * Sec 3
 * 22102544
 * CS202 hw 4
 * Input example: ./a.out "S Apple\nS Chips\nS Cheese\nS Crackers\nC Apple Chips\nC Cheese Crackers\nC Crackers Apple\nC Crackers Chips\nL Crackers\nL Chips\nD Crackers Cheese\nL Crackers\nQ Apple Chips\nQ Cheese Crackers\nX"
 */
#ifndef HW5_CS_202_ACCOMPANIMENTHASHING_H
#define HW5_CS_202_ACCOMPANIMENTHASHING_H

#include "alara_zeybek_22102544_Accompaniment.h"
class AccompanimentHashing {
public:
    AccompanimentHashing();
    ~AccompanimentHashing();
    bool addNewAcc(string s1,string s2, SnackHashing& sh, string& accName);
    bool deleteAcc(string s1,string s2,SnackHashing& SH);
    bool checkAcc(string s1,string s2);
    Accompaniment* findAccInTable(string s, int& foundAt);

    void printAccTable();
private:
    const int tablesize = 71;
    Accompaniment* table[71];
    int hash(string s) ;
};


#endif //HW5_CS_202_ACCOMPANIMENTHASHING_H
