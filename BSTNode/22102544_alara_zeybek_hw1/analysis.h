/**
* Title: Binary Search Trees
* Author : ALARA ZEYBEK
* ID: 22102544
* Section : 3
* Homework :1
* Description :
*/
#ifndef analysis_h
#define analysis_h
#include "BST.h"
#include <stdio.h>
class analysis{
public:
    void insertBST(int*& arr, int size, int start, BST*& tree);
    void createArr(int*& arr, int size);
    void Shuffle(int*& arr, int size);
    void onlyDelete(int*& arr, BST*& tree, int size, int firstIndex);
    void createArrOrdered(int*& arr, int size);
};

#endif
