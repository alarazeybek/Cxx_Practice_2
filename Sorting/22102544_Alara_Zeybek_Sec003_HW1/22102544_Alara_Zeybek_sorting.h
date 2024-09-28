/**
* Title: Algorithm analysis & Sorting
* Author : Alara Zeybek
* Id: 22102544
* Section : 3
* Homework : 1
* Description : sorting algorithms' implementations
*/

#ifndef sorting_h
#define sorting_h
#include <iostream>
#include "string"
using namespace std;

class sorting {
    private:
        void swap(int &x, int &y);
        void mergeSortHelp(int& left, int& right, int* arr, int &compCount, int &moveCount );
        void mergeHelp(int& left, int& right, int& mid, int* arr, int &compCount, int &moveCount );
        //void quickSortHelp(int& left, int& right, int* arr, int &compCount, int &moveCount );
        void quickSortHelp(int left, int right, int* arr, int &compCount, int &moveCount );
        int partition(int left, int right, int* arr, int &compCount, int &moveCount );
        //int partition(int& left, int& right, int* arr, int &compCount, int &moveCount );
    public:   
        void insertionSort(int *arr, const int size, int &compCount, int &moveCount);
        void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
        void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
        void quickSort(int *arr, const int size, int &compCount, int &moveCount);
        void hybritSort(int *arr, const int size, int &compCount, int &moveCount);
};
#endif