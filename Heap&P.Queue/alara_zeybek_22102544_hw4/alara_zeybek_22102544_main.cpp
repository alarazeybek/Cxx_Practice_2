/*
 * Alara Zeybek
 * Sec 3
 * 22102544
 * CS202 hw 4
 * Input example: ./a.out "S Apple\nS Chips\nS Cheese\nS Crackers\nC Apple Chips\nC Cheese Crackers\nC Crackers Apple\nC Crackers Chips\nL Crackers\nL Chips\nD Crackers Cheese\nL Crackers\nQ Apple Chips\nQ Cheese Crackers\nX"
 */
#include <iostream>
#include "alara_zeybek_22102544_AccompanimentHashing.h"
#include "alara_zeybek_22102544_SnackHashing.h"
using namespace std;

int main(int argc, char* argv[]) {
    if(argc < 2){
        cout << "The input string is missing" << endl;
        return 1;
    }
    SnackHashing h;
    AccompanimentHashing ach;
    string input = argv[1];
    size_t d = input.find(static_cast<char>('\\n'));
    string substr = input.substr(0, d - 1);
    while(substr[0] != 'X'){
        switch (substr[0]) {
            case 'S': {
                string substr2 = substr.substr(2, d - 2);
                bool b;
                b = h.addNewSnack(substr2);
                if(b)
                    cout<<"Snack '"<<substr2<<"' created\n";
                break;
            }
            case 'C': {
                string substr2 = substr.substr(2, d - 3);
                size_t w1 = substr2.find(' ');
                string nameofsnack = substr2.substr(0, w1);//first snack
                string nameofsnack2 = substr.substr(w1 + 3, d- 9);//second snack
                if (nameofsnack2 != nameofsnack) {
                    string str;
                    ach.addNewAcc(nameofsnack,nameofsnack2,h,str);
                }
                break;
            }
            case 'D': {
                string substr2 = substr.substr(2, d - 3);
                size_t w1 = substr2.find(' ');
                string nameofsnack = substr2.substr(0, w1);//first snack
                //string substr3 = substr.substr(w1 + 3, d - 3);
                //size_t w2 = substr2.find(' ');
                string nameofsnack2 = substr.substr(w1 + 3, d- 9);//second snack
                if(nameofsnack!=nameofsnack2)
                    ach.deleteAcc(nameofsnack,nameofsnack2,h);
                break;
            }
            case 'L': {
                string substr2 = substr.substr(2, d);
                h.printAccofSpecificSnack(substr2);
                break;
            }
            case 'Q': {
                string substr2 = substr.substr(2, d);
                size_t w1 = substr2.find(' ');
                string nameofsnack = substr2.substr(0,w1);//first snack
                string substr3 = substr.substr(w1+1, d);
                //size_t w2 = substr2.find(' ');
                string nameofsnack2 = substr2.substr(w1+1,d);//second snack
                bool b = ach.checkAcc(nameofsnack,nameofsnack2);
                if(b){
                    cout << "Yes" << endl;
                }
                else{
                    cout << "No" << endl;
                }
                break;
            }
            default: {
                cout << "You have entered a invalid operation type." << endl;
                break;
            }
        }
        size_t d1 = d;
        input = input.substr(d+1);
        d = input.find(static_cast<char>('\\n'));
        substr = input.substr(0, d - 1);
    }
    return 0;
}