/**
* Title: Binary Search Trees
* Author : ALARA ZEYBEK
* ID: 22102544
* Section : 3
* Homework : 2
* Description :
*/
#include "analysis.h"
#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
using namespace std;

void analysis::insertBST(int *&arr, int size, int start, BST* &tree){
    for(int a = 0; a < size; a++){
        (*tree).insertItem(arr[a+start]);
    }
}
void analysis::createArr(int*& arr, int size){
    arr = new int[size];
    srand(time(0));
    for(int a = 0; a < size; a++){
        arr[a] = rand();
    }
}
void analysis::Shuffle(int *&arr, int size){
    random_device r;
    mt19937 m(r());
    shuffle(arr, arr + size, m);
}
void analysis::onlyDelete(int *&arr, BST *&tree, int size, int firstIndex) {
    for(int a = 0; a < size; a++){
        (*tree).deleteItem(arr[a+firstIndex]);
    }
}
