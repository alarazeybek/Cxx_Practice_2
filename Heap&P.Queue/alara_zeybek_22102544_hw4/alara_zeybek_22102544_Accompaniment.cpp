/*
 * Alara Zeybek
 * Sec 3
 * 22102544
 * CS202 hw 4
 * Input example: ./a.out "S Apple\nS Chips\nS Cheese\nS Crackers\nC Apple Chips\nC Cheese Crackers\nC Crackers Apple\nC Crackers Chips\nL Crackers\nL Chips\nD Crackers Cheese\nL Crackers\nQ Apple Chips\nQ Cheese Crackers\nX"
 */
#include "alara_zeybek_22102544_Accompaniment.h"
Accompaniment::Accompaniment() : f_objectPTR(nullptr), s_objectPTR(nullptr){

}
Accompaniment::Accompaniment(Snack* s1, Snack* s2, SnackHashing& snackHashTable){
    if((s1 != nullptr && s2 != nullptr) ){
        if (s1->getName() != s2->getName()) {
            bool b = s1->getName() < s2->getName();   // a < z is true=1
            if (b) {
                accompaniment_name = s1->getName() + s2->getName();

                //Snack *s2Temp = snackHashTable.findSnackInTable(s2->getName());
                f_objectPTR = s2->addAccompanied(s1->getName());

                //Snack *s1Temp = snackHashTable.findSnackInTable(s1->getName());
                s_objectPTR = s1->addAccompanied(s2->getName());
            } else {
                accompaniment_name = s2->getName() + s1->getName();
                //Snack *s2Temp = snackHashTable.findSnackInTable(s1->getName());
                f_objectPTR = s1->addAccompanied(s2->getName()); // apple in chips'linkedList

                //Snack *s1Temp = snackHashTable.findSnackInTable(s2->getName());
                s_objectPTR = s2->addAccompanied(s1->getName());// chips in apple'linkedList
            }
        }
        else{
            Accompaniment();
        }
    }
    else{
        Accompaniment();
    }
}

string Accompaniment::getAccompaniment_name(){
    return accompaniment_name;
}
bool Accompaniment::isNullObj(){
    if(f_objectPTR == nullptr){
        return true;
    }
    return false;
}