/*
 * Alara Zeybek
 * Sec 3
 * 22102544
 * CS202 hw 4
 * Input example: ./a.out "S Apple\nS Chips\nS Cheese\nS Crackers\nC Apple Chips\nC Cheese Crackers\nC Crackers Apple\nC Crackers Chips\nL Crackers\nL Chips\nD Crackers Cheese\nL Crackers\nQ Apple Chips\nQ Cheese Crackers\nX"
 */
#ifndef ACCOMPANIMENT_H
#define ACCOMPANIMENT_H
#include "iostream"
#include "alara_zeybek_22102544_Snack.h"
#include "alara_zeybek_22102544_SnackHashing.h"
using namespace std;

class Accompaniment {
public:
    Accompaniment();
    Accompaniment(Snack* s1, Snack* s2, SnackHashing& snackHashTable);
    string getAccompaniment_name();
    bool isNullObj();
    Snack* f_objectPTR;  //snacklerden second object i bul. Snack classındaki linkedlistte first_objecti bul ve işaret et
    Snack* s_objectPTR;  //snacklerden first object i bul. Snack classındaki linkedlistte second_objecti bul ve işaret ets
private:
    string accompaniment_name;

};


#endif
