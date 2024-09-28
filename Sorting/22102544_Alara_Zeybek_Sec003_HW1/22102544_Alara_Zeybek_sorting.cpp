/**
* Title: Algorithm analysis & Sorting
* Author : Alara Zeybek
* Id: 22102544
* Section : 3
* Homework : 1
* Description : sorting algorithms' implementations
*/

#include <iostream>
#include "22102544_Alara_Zeybek_sorting.h"
#include "string"
using namespace std;


void sorting::swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void sorting::insertionSort(int *arr, const int size, int &compCount, int &moveCount){
    for(int i = 1; i<size; i++){
        int k = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > k ){
            arr[j+1] = arr[j];
            j--;
            compCount++;
            moveCount++;
        }
        arr[j+1] = k;
        moveCount++;
    }
}
void sorting::bubbleSort(int *arr, const int size, int &compCount, int &moveCount){
    for(int i = size-1; i>0 ;i--){
        for(int j = 0; j < i; j++){
            if( arr[j] > arr[j+1] ){
                swap(arr[j],arr[j+1]);
                moveCount++;
            }
            compCount++;
        }
    }

}
void sorting::mergeSortHelp(int& left, int& right, int* arr, int &compCount, int &moveCount ){
    if(left >= right || right-left < 1){
        return;
    }
    int mid = (right+left) / 2;
    
    mergeSortHelp(left,mid,arr,compCount,moveCount);
    mid++;
    mergeSortHelp(mid,right,arr,compCount,moveCount);
    mid--;
    mergeHelp(left,right, mid, arr, compCount, moveCount);
}

void sorting::mergeHelp(int& left, int& right, int& mid, int* arr, int &compCount, int &moveCount ){
    int part1Length = (mid-left)+1;
    int part2Length = right-mid;
    int arr1[part1Length];
    int arr2[part2Length];

    for(int i = 0; i<part1Length;i++){
        arr1[i] = arr[i+left];
    }
    for(int i = 0; i<part2Length;i++){
        arr2[i] = arr[i+mid+1];
    }
    int k = left; //main array index
    int i=0, j = 0; //subarrays indexes

    while( i< part1Length && j<part2Length){
        if(arr1[i]<arr2[j]){
            arr[k] = arr1[i];
            i++;
        }
        else{
            arr[k] = arr2[j];
            j++;
        }
        k++;
        compCount++;
        moveCount++;
    }
    if(i>=part1Length){
        while(j<part2Length){
            arr[k] = arr2[j];
            k++;
            j++;
            moveCount++;
        }
    }
    else if(j>=part2Length){
        while(i<part1Length){
            arr[k] = arr1[i];
            k++;
            i++;
            moveCount++;
        }
    }
}
void sorting::mergeSort(int *arr, const int size, int &compCount, int &moveCount){
    int end = size-1;
    int start = 0;
    mergeSortHelp( start , end , arr, compCount, moveCount);
}

/*
void sorting::quickSortHelp(int& left, int& right, int* arr, int &compCount, int &moveCount ){
    if(left<right){
            int pivot = partition(left,right,arr,compCount,moveCount);
            pivot--;
            quickSortHelp(left, pivot, arr,compCount,moveCount); //before
            pivot += 2;
            quickSortHelp( pivot, right, arr,compCount,moveCount); //after
        }
}
int sorting::partition(int& left, int& right, int* arr, int &compCount, int &moveCount ){
    //cout<<left<<"   "<<right<<endl;
    int* pivot = &arr[right]; //en sağ pivot
   // cout<<*pivot<<endl;
    int j = *pivot -1;
    int i = 0;
   while(i<j){
        while(arr[i] < *pivot && i<left+right){
            i++;
        }
        while(arr[j] > *pivot && j>left){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    cout<<j<<endl;
    swap(arr[j],*pivot);
    return j;
}
*/

void sorting::quickSortHelp(int left, int right, int* arr, int &compCount, int &moveCount ){
    if(left < right){
        int pivotIndex = partition (left, right, arr, compCount, moveCount);
        quickSortHelp(left, pivotIndex-1, arr,compCount,moveCount); //before
        quickSortHelp( pivotIndex+1, right, arr,compCount,moveCount); //after
    }
}
int sorting::partition(int left, int right, int* arr, int &compCount, int &moveCount ){
    if(left < right){
        int pivot = arr[right];
        int i = right; 
        int j = right -1;

        while( j >= left){
            if(arr[j] > pivot){
                i--;
                swap(arr[i],arr[j]);
                compCount++;
                moveCount++;
            }
            j--;
        }
        swap(arr[right], arr[i]);
        moveCount++;
        return i;
    }
    return -1;
}

void sorting::quickSort(int *arr, const int size, int &compCount, int &moveCount){
    int end = size-1;
    int start = 0;
    quickSortHelp( start , end , arr, compCount, moveCount);
}

void sorting::hybritSort(int *arr, const int size, int &compCount, int &moveCount){
    if(size <= 20){
        bubbleSort(arr, size, compCount, moveCount);
    }
    else{
        quickSort(arr, size, compCount, moveCount);
    }
}
