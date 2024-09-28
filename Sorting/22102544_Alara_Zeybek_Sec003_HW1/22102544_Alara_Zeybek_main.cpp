/**
* Title: Algorithm analysis & Sorting
* Author : Alara Zeybek
* Id: 22102544
* Section : 3
* Homework : 1
* Description : sorting algorithms' implementations
*/
#include <stdio.h>
#include <algorithm>
#include "22102544_Alara_Zeybek_sorting.h"
#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std;

void printArray(int* arr, const int& size);
void ArrayGeneratorHelper( int* arr, int startIndex, int partSize, bool asOrDes, int size);

void RandomArrayGenerator(int* arr, int& size);
void P_AscendingGenerator(int* arr, int& size);
void P_DescendingGenerator(int* arr, int& size);

void Execution1(sorting& s,int* array, int const size, string sortName);
void Execution2(sorting& s,int* array, int const size, string sortName);
void Execution3(sorting& s,int* array, int const size, string sortName);
void Execution4(sorting& s,int* array, int const size, string sortName);
void Execution5(sorting& s, int* array, int const size, string sortName);


int main(){
    sorting s;
    bool firstRound = 1;
    int SIZE_A = 1000;
    int SIZE_B = 1000;
    int SIZE_C = 1000;
    int i = 4;
    
        cout<<"Part 2-b-1: Performance analysis of random integers array"<<endl;
        cout << "---------------------------------------------------------------------------"<<endl;
        printf("%28s %12s %10s\n", "Elapsed time" , "Comp. Count", "Move Count");
        cout<<"Array Size:"<<SIZE_A<<endl;

        int* a = new int[SIZE_A];
        int* a_2 = new int[SIZE_A];

        RandomArrayGenerator(a, SIZE_A);
        copy_n(a, SIZE_A, a_2);
        Execution1(s,a_2,SIZE_A,"Insertion Sort");
        copy_n(a, SIZE_A, a_2);
        Execution2(s,a_2,SIZE_A,"Bubble Sort");
        copy_n(a, SIZE_A, a_2);
        Execution3(s,a_2,SIZE_A,"Merge Sort");
        copy_n(a, SIZE_A, a_2);
        Execution4(s,a_2,SIZE_A,"Quick Sort");
        copy_n(a, SIZE_A, a_2);
        Execution5(s,a_2,SIZE_A,"Hybrit Sort");

        delete[] a;
        delete[] a_2;

        SIZE_A = 5000;
        cout << "---------------------------------------------------------------------------"<<endl;
        printf("%28s %12s %10s\n", "Elapsed time" , "Comp. Count", "Move Count");
        cout<<"Array Size:"<<SIZE_A<<endl;
        a = new int[SIZE_A];
        a_2 = new int[SIZE_A];

        RandomArrayGenerator(a, SIZE_A);
        copy_n(a, SIZE_A, a_2);
        Execution1(s,a_2,SIZE_A,"Insertion Sort");
        copy_n(a, SIZE_A, a_2);
        Execution2(s,a_2,SIZE_A,"Bubble Sort");
        copy_n(a, SIZE_A, a_2);
        Execution3(s,a_2,SIZE_A,"Merge Sort");
        copy_n(a, SIZE_A, a_2);
        Execution4(s,a_2,SIZE_A,"Quick Sort");
        copy_n(a, SIZE_A, a_2);
        Execution5(s,a_2,SIZE_A,"Hybrit Sort");

        delete[] a;
        delete[] a_2;

        SIZE_A = 10000;
        cout << "---------------------------------------------------------------------------"<<endl;
        printf("%28s %12s %10s\n", "Elapsed time" , "Comp. Count", "Move Count");
        cout<<"Array Size:"<<SIZE_A<<endl;

        a = new int[SIZE_A];
        a_2 = new int[SIZE_A];

        RandomArrayGenerator(a, SIZE_A);
        copy_n(a, SIZE_A, a_2);
        Execution1(s,a_2,SIZE_A,"Insertion Sort");
        copy_n(a, SIZE_A, a_2);
        Execution2(s,a_2,SIZE_A,"Bubble Sort");
        copy_n(a, SIZE_A, a_2);
        Execution3(s,a_2,SIZE_A,"Merge Sort");
        copy_n(a, SIZE_A, a_2);
        Execution4(s,a_2,SIZE_A,"Quick Sort");
        copy_n(a, SIZE_A, a_2);
        Execution5(s,a_2,SIZE_A,"Hybrit Sort");

        delete[] a;
        delete[] a_2;

        SIZE_A = 20000;
        cout << "---------------------------------------------------------------------------"<<endl;
        printf("%28s %12s %10s\n", "Elapsed time" , "Comp. Count", "Move Count");
        cout<<"Array Size:"<<SIZE_A<<endl;

        a = new int[SIZE_A];
        a_2 = new int[SIZE_A];

        RandomArrayGenerator(a, SIZE_A);
        copy_n(a, SIZE_A, a_2);
        Execution1(s,a_2,SIZE_A,"Insertion Sort");
        copy_n(a, SIZE_A, a_2);
        Execution2(s,a_2,SIZE_A,"Bubble Sort");
        copy_n(a, SIZE_A, a_2);
        Execution3(s,a_2,SIZE_A,"Merge Sort");
        copy_n(a, SIZE_A, a_2);
        Execution4(s,a_2,SIZE_A,"Quick Sort");
        copy_n(a, SIZE_A, a_2);
        Execution5(s,a_2,SIZE_A,"Hybrit Sort");

        delete[] a;
        delete[] a_2;

        cout<<"\nPart 2-b-2: Performance analysis of partially ascending integers array"<<endl;
        cout << "---------------------------------------------------------------------------"<<endl;
        printf("%28s %12s %10s\n", "Elapsed time" , "Comp. Count", "Move Count");
        cout<<"Array Size:"<<SIZE_B<<endl;

        int* b = new int[SIZE_B];
        int* b_2 = new int[SIZE_B];

        RandomArrayGenerator(b, SIZE_B);
        copy_n(b, SIZE_B, b_2);
        Execution1(s,b_2,SIZE_B,"Insertion Sort");
        copy_n(b, SIZE_B, b_2);
        Execution2(s,b_2,SIZE_B,"Bubble Sort");
        copy_n(b, SIZE_B, b_2);
        Execution3(s,b_2,SIZE_B,"Merge Sort");
        copy_n(b, SIZE_B, b_2);
        Execution4(s,b_2,SIZE_B,"Quick Sort");
        copy_n(b, SIZE_B, b_2);
        Execution5(s,b_2,SIZE_B,"Hybrit Sort");

        delete[] b;
        delete[] b_2;

        SIZE_B = 5000;
        cout << "---------------------------------------------------------------------------"<<endl;
        printf("%28s %12s %10s\n", "Elapsed time" , "Comp. Count", "Move Count");
        cout<<"Array Size:"<<SIZE_B<<endl;

        b = new int[SIZE_B];
        b_2 = new int[SIZE_B];

        RandomArrayGenerator(b, SIZE_B);
        copy_n(b, SIZE_B, b_2);
        Execution1(s,b_2,SIZE_B,"Insertion Sort");
        copy_n(b, SIZE_B, b_2);
        Execution2(s,b_2,SIZE_B,"Bubble Sort");
        copy_n(b, SIZE_B, b_2);
        Execution3(s,b_2,SIZE_B,"Merge Sort");
        copy_n(b, SIZE_B, b_2);
        Execution4(s,b_2,SIZE_B,"Quick Sort");
        copy_n(b, SIZE_B, b_2);
        Execution5(s,b_2,SIZE_B,"Hybrit Sort");

        delete[] b;
        delete[] b_2;

        SIZE_B = 10000;
        cout << "---------------------------------------------------------------------------"<<endl;
        printf("%28s %12s %10s\n", "Elapsed time" , "Comp. Count", "Move Count");
        cout<<"Array Size:"<<SIZE_B<<endl;

        b = new int[SIZE_B];
        b_2 = new int[SIZE_B];

        RandomArrayGenerator(b, SIZE_B);
        copy_n(b, SIZE_B, b_2);
        Execution1(s,b_2,SIZE_B,"Insertion Sort");
        copy_n(b, SIZE_B, b_2);
        Execution2(s,b_2,SIZE_B,"Bubble Sort");
        copy_n(b, SIZE_B, b_2);
        Execution3(s,b_2,SIZE_B,"Merge Sort");
        copy_n(b, SIZE_B, b_2);
        Execution4(s,b_2,SIZE_B,"Quick Sort");
        copy_n(b, SIZE_B, b_2);
        Execution5(s,b_2,SIZE_B,"Hybrit Sort");

        delete[] b;
        delete[] b_2;
        
        SIZE_B = 20000;
        cout << "---------------------------------------------------------------------------"<<endl;
        printf("%28s %12s %10s\n", "Elapsed time" , "Comp. Count", "Move Count");
        cout<<"Array Size:"<<SIZE_B<<endl;

        b = new int[SIZE_B];
        b_2 = new int[SIZE_B];

        P_DescendingGenerator(b, SIZE_B);

        copy_n(b, SIZE_B, b_2);
        Execution1(s,b_2,SIZE_B,"Insertion Sort");
        copy_n(b, SIZE_B, b_2);
        Execution2(s,b_2,SIZE_B,"Bubble Sort");
        copy_n(b, SIZE_B, b_2);
        Execution3(s,b_2,SIZE_B,"Merge Sort");
        copy_n(b, SIZE_B, b_2);
        Execution4(s,b_2,SIZE_B,"Quick Sort");
        copy_n(b, SIZE_B, b_2);
        Execution5(s,b_2,SIZE_B,"Hybrit Sort");

        delete[] b;
        delete[] b_2;
    
    
        cout<<"\nPart 2-b-3: Performance analysis of partially descending integers array"<<endl;
        cout << "---------------------------------------------------------------------------"<<endl;
        printf("%28s %12s %10s\n", "Elapsed time" , "Comp. Count", "Move Count");
        cout<<"Array Size:"<<SIZE_C<<endl;

        int* c = new int[SIZE_C];
        int* c_2 = new int[SIZE_C];

        P_DescendingGenerator(c, SIZE_C);
        copy_n(c, SIZE_C, c_2);
        Execution1(s,c_2,SIZE_C,"Insertion Sort");
        copy_n(c, SIZE_C, c_2);
        Execution2(s,c_2,SIZE_C,"Bubble Sort");
        copy_n(c, SIZE_C, c_2);
        Execution3(s,c_2,SIZE_C,"Merge Sort");
        copy_n(c, SIZE_C, c_2);
        Execution4(s,c_2,SIZE_C,"Quick Sort");
        copy_n(c, SIZE_C, c_2);
        Execution5(s,c_2,SIZE_C,"Hybrit Sort");

        delete[] c;
        delete[] c_2;

        SIZE_C = 5000;
        cout << "---------------------------------------------------------------------------"<<endl;
        printf("%28s %12s %10s\n", "Elapsed time" , "Comp. Count", "Move Count");
        cout<<"Array Size:"<<SIZE_C<<endl;

        c = new int[SIZE_C];
        c_2 = new int[SIZE_C];

        P_DescendingGenerator(c, SIZE_C);
        copy_n(c, SIZE_C, c_2);
        Execution1(s,c_2,SIZE_C,"Insertion Sort");
        copy_n(c, SIZE_C, c_2);
        Execution2(s,c_2,SIZE_C,"Bubble Sort");
        copy_n(c, SIZE_C, c_2);
        Execution3(s,c_2,SIZE_C,"Merge Sort");
        copy_n(c, SIZE_C, c_2);
        Execution4(s,c_2,SIZE_C,"Quick Sort");
        copy_n(c, SIZE_C, c_2);
        Execution5(s,c_2,SIZE_C,"Hybrit Sort");

        delete[] c;
        delete[] c_2;

        SIZE_C = 10000;
        cout << "---------------------------------------------------------------------------"<<endl;
        printf("%28s %12s %10s\n", "Elapsed time" , "Comp. Count", "Move Count");
        cout<<"Array Size:"<<SIZE_C<<endl;

        c = new int[SIZE_C];
        c_2 = new int[SIZE_C];

        P_DescendingGenerator(c, SIZE_C);
        copy_n(c, SIZE_C, c_2);
        Execution1(s,c_2,SIZE_C,"Insertion Sort");
        copy_n(c, SIZE_C, c_2);
        Execution2(s,c_2,SIZE_C,"Bubble Sort");
        copy_n(c, SIZE_C, c_2);
        Execution3(s,c_2,SIZE_C,"Merge Sort");
        copy_n(c, SIZE_C, c_2);
        Execution4(s,c_2,SIZE_C,"Quick Sort");
        copy_n(c, SIZE_C, c_2);
        Execution5(s,c_2,SIZE_C,"Hybrit Sort");

        delete[] c;
        delete[] c_2;

        SIZE_C = 20000;
        cout << "---------------------------------------------------------------------------"<<endl;
        printf("%28s %12s %10s\n", "Elapsed time" , "Comp. Count", "Move Count");
        cout<<"Array Size:"<<SIZE_C<<endl;

        c = new int[SIZE_C];
        c_2 = new int[SIZE_C];

        P_DescendingGenerator(c, SIZE_C);
        copy_n(c, SIZE_C, c_2);
        Execution1(s,c_2,SIZE_C,"Insertion Sort");
        copy_n(c, SIZE_C, c_2);
        Execution2(s,c_2,SIZE_C,"Bubble Sort");
        copy_n(c, SIZE_C, c_2);
        Execution3(s,c_2,SIZE_C,"Merge Sort");
        copy_n(c, SIZE_C, c_2);
        Execution4(s,c_2,SIZE_C,"Quick Sort");
        copy_n(c, SIZE_C, c_2);
        Execution5(s,c_2,SIZE_C,"Hybrit Sort");

        delete[] c;
        delete[] c_2;
    
}
void printArray(int* arr, const int& size){
    for(int i = 0; i<size;i++){
        cout<<arr[i]<<endl;
    }
}
void ArrayGeneratorHelper( int* arr, int startIndex, int partSize, bool asOrDes, int size){
    if(asOrDes){
        for(int a = 1+startIndex; a <= startIndex + partSize; a++){       //sorted start to end ascending
            if(a + partSize > size){
                break;
            }
            arr[a-1] = a;
        }
    }
    else{
        for(int a = startIndex; a >= startIndex - partSize ; a--){       //sorted start to end descending
            if(a - partSize < -1){
                break;
            }
            arr[size - a] = a;
        }
    }
    for(int a = 0; a < partSize; a++){
        if(partSize == 0){
            break;
        }
        int randomIndex = rand() % partSize + 0;        // 0 to partSize
        if(a + startIndex < 0 || a + startIndex >= size || startIndex + randomIndex < 0 || startIndex + randomIndex){
            break;
        }
        swap(arr[a+startIndex] , arr[ startIndex + randomIndex]);
    }
}
void RandomArrayGenerator(int* arr, int& size ){
    srand(time(0));
    for(int a = 0; a < size; a++){
        arr[a] = rand();
    }
   //ArrayGeneratorHelper(arr,0,size,1, size);
}

void P_AscendingGenerator(int* arr, int& size){
    for(int a = 0; a < size; a++){
            arr[a] = a;
        }
    random_device r;
    mt19937 m(r());
    for(int a = 0; a < size; a += log2(size)){
        if(a + log2(size) > size){
            break;
        }
        shuffle(arr + a, arr + static_cast<int>(( a + log2(size))) + 1, m);
    }
}

void P_DescendingGenerator(int* arr, int& size){
    for(int a = size; a > 0; a--){
        arr[size - a] = a;
    }
    random_device r;
    mt19937 m(r());
    for(int a = 0; a < size; a += log2(size)){
        if(a + log2(size) > size){
            break;
        }
        shuffle(arr + a, arr + static_cast<int>(( a + log2(size))) + 1, m);
    }
}

//------------------------------ALGORITHM CALLS------------------------------------
void Execution5(sorting& s, int* array, int const size, string sortName){    //HYBRIT
    double duration = 0.0;
    int compCount = 0;
    int moveCount = 0;
    clock_t startTime = clock();
    s.hybritSort(array, size, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    printf("%-15s %-13f %-11d %-10d \n", sortName.c_str(),duration, compCount, moveCount);
}
void Execution4(sorting& s, int* array, int const size, string sortName){    //QUICK
    double duration = 0.0;
    int compCount = 0;
    int moveCount = 0;
    clock_t startTime = clock();
    s.quickSort(array, size, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    printf("%-15s %-13f %-11d %-10d \n", sortName.c_str(),duration, compCount, moveCount);
}
void Execution3(sorting& s,int* array, int const size, string sortName){    //MERGE
    double duration = 0.0;
    int compCount = 0;
    int moveCount = 0;
    clock_t startTime = clock();
    s.mergeSort(array, size, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    printf("%-15s %-13f %-11d %-10d \n", sortName.c_str(),duration, compCount, moveCount);
}
void Execution2(sorting& s,int* array, int const size, string sortName){    //BUBBLE
    double duration = 0.0;
    int compCount = 0;
    int moveCount = 0;
    clock_t startTime = clock();
    s.bubbleSort(array, size, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    printf("%-15s %-13f %-11d %-10d \n", sortName.c_str(),duration, compCount, moveCount);
}
void Execution1(sorting& s,int* array, int const size, string sortName){    //ıNSERTION
    double duration = 0.0;
    int compCount = 0;
    int moveCount = 0;
    clock_t startTime = clock();
    s.insertionSort(array, size, compCount, moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    printf("%-15s %-13f %-11d %-10d \n", sortName.c_str(),duration, compCount, moveCount);

}
