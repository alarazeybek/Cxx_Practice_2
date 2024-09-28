/*
 * Alara Zeybek
 * Sec 3
 * 22102544
 * CS202 hw 4
 * Input example: ./a.out "S Apple\nS Chips\nS Cheese\nS Crackers\nC Apple Chips\nC Cheese Crackers\nC Crackers Apple\nC Crackers Chips\nL Crackers\nL Chips\nD Crackers Cheese\nL Crackers\nQ Apple Chips\nQ Cheese Crackers\nX"
 */

#include "alara_zeybek_22102544_AccompanimentHashing.h"
#include "alara_zeybek_22102544_Accompaniment.h"
#include "iostream"
using namespace std;

AccompanimentHashing::AccompanimentHashing() {
    for(int i = 0; i<tablesize;i++)
        table[i] = nullptr;
}
AccompanimentHashing::~AccompanimentHashing() {
    for(int i = 0; i<tablesize;i++) {
        if (table[i] != nullptr) {
            delete table[i];
        }
    }
}

bool AccompanimentHashing::addNewAcc(string s1,string s2, SnackHashing& sh, string& accName) {
    Accompaniment* ptr = new Accompaniment(sh.findSnackInTable(s1),sh.findSnackInTable(s2) ,sh);
    accName = ptr->getAccompaniment_name();
    int index_hash = hash(ptr->getAccompaniment_name());
    int i = 0;
    int index ;
    do{
        index = index_hash + i*i;
            if( table[i] == nullptr){
                //delete table[index];
                table[index] = ptr;
                return true;
        }
        i++;
    }while(index < tablesize );
    return false;
}

bool AccompanimentHashing::deleteAcc(string s1,string s2,SnackHashing& SH) {
    string str = s2+s1;
    if(s1<s2){
        str = s1+s2;
    }
    int index;
    Accompaniment* item = findAccInTable(str,index);
    if(item->getAccompaniment_name() == str){
        Snack* s1 = SH.findSnackInTable(item->s_objectPTR->getName());
        Snack* s2 = SH.findSnackInTable(item->f_objectPTR->getName());
        s1->deleteAccompanied(item->f_objectPTR->getName());
        s2->deleteAccompanied(item->s_objectPTR->getName());
        delete table[index]; //emin degilim
        table[index] = nullptr;
        return true;
    }
    return false;
}

Accompaniment* AccompanimentHashing::findAccInTable(string s,  int& foundAt) {
    int index_hash = hash(s);
    int i = 0;
    int index = 0;
    do{
        index = index_hash + i*i;
        i++;
    }while( table[index]!= nullptr && table[index]->getAccompaniment_name() != s);
    foundAt = index;
    return table[index];
}

int AccompanimentHashing::hash(string s)  {
    int index = 0;
    for (int i = 0; i < s.length(); i++)
    {
        index += (int)s[i];
    }
    return index % tablesize;
}

void AccompanimentHashing::printAccTable() {
    for(int i = 0; i<tablesize; i++){
        cout<<"Index "<< i <<" element: ";
        if(table[i]!= nullptr){
                cout<<table[i]->getAccompaniment_name();
        }
        cout<<endl;
    }
}

bool AccompanimentHashing::checkAcc(string s1,string s2){
    string str = s2+s1;
    if(s1<s2){
        str = s1+s2;
    }
    int index;
    Accompaniment* item = findAccInTable(str,index);
    if(item == nullptr ){
        return false;
    }
    else if(item->getAccompaniment_name() != str)
        return false;
    else
        return true;
}
