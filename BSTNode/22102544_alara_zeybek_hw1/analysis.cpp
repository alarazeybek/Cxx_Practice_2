/**
* Title: Binary Search Trees
* Author : ALARA ZEYBEK
* ID: 22102544
* Section : 3
* Homework : 1
* Description :
*/
#include "analysis.h"
#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
using namespace std;

void timeAnalysis();
void printArray(string const treeName, int const arraySize, int* arr);

void analysis::insertBST(int *&arr, int size, int start, BST* &tree){
    for(int a = 0; a < size; a++){
        (*tree).insertKeyWithoutPrint(arr[a+start]);
    }
}
void analysis::createArr(int*& arr, int size){
    arr = new int[size];
    srand(time(0));
    for(int a = 0; a < size; a++){
        arr[a] = rand();
    }
    Shuffle(arr,size);
}
void analysis::createArrOrdered(int*& arr, int size){
    arr = new int[size];
    for(int a = 0; a < size; a++){
        arr[a] = a;
    }
}
void analysis::Shuffle(int *&arr, int size){
    random_device r;
    mt19937 m(r());
    shuffle(arr, arr + size, m);
}
void analysis::onlyDelete(int *&arr, BST *&tree, int size, int firstIndex) {
    for(int a = 0; a < size; a++){
        (*tree).deleteKeyWithoutPrint(arr[a+firstIndex]);
    }
}
