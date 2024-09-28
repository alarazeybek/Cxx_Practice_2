//
// Created by DELL on 29.04.2024.
//

#include <algorithm>
#include "Subtask2.h"
#include <iostream>
using namespace std;

bool Subtask2::comparetupleTask2(const tupleTask2& a, const tupleTask2& b) {
    // First, compare by hash1 in descending order
    if (a.hash_value1 != b.hash_value1) {
        return a.hash_value1 > b.hash_value1;
    }
    // If hash1 values are equal, compare by hash2
    return a.hash_value2 > b.hash_value2;
}
Subtask2::Subtask2(string str, string *tuple_list, int n_val, int m_val) {
    main_str = str;
    n = n_val;
    m = m_val;
    k = str.size();
    tupleArr_ptr = new tupleTask2[m];
    freArr_ptr = new int[n];
    // initializing the frequencies.
    for (int i = 0; i < n; ++i){
        freArr_ptr[i] = 0;
    }
    // initializing the tuples.
    int tuple_id = 0;
    for (int i = 0; i < m; ++i) {
        string tuple = tuple_list[i];
        int hash_val1 = hashFunction1(tuple);
        int hash_val2 = hashFunction2(tuple);
        tupleArr_ptr[i] = tupleTask2(tuple, hash_val1, hash_val2, tuple_id++); // adding tuple
        if (tuple.size() < k){ // Length of the shortest pattern
            k = tuple.size();
        }
    }
    // Sort the tupleArr_ptr array using comparetupleTask2 function
    sort(tupleArr_ptr, tupleArr_ptr + m, comparetupleTask2);

    for(int i = 0; i <= 5; ++i){ // O(1)
        int slice_size = k+i;
        for (int j = 0; j <= n-slice_size; ++j){ // O(1) assuming n is relatively small number
            string substring = main_str.substr(j,  slice_size);
            int hash1_val = hashFunction1(substring);
            int hash2_val = hashFunction2(substring);
            int t_id = binarySearch(hash1_val,hash2_val);
            //cout<<"-----"<< substring << endl;
            if (t_id != -1){
                freArr_ptr[t_id]++;
            }
        }
    }
    printFrequency();
}

Subtask2::~Subtask2(){
    delete[] freArr_ptr;
    delete[] tupleArr_ptr;
}

void Subtask2::traverseStringInKParts() {
    for(int i = 0; i <= 5; ++i){ // O(1)
        int slice_size = k+i;
        for (int j = 0; j <= n-slice_size; ++j){ // O(1) assuming n is relatively small number
            string substring = main_str.substr(j,  slice_size);
            int hash1_val = hashFunction1(substring);
            int hash2_val = hashFunction2(substring);
            int t_id = binarySearch(hash1_val,hash2_val);
            //cout<<"-----"<< substring << endl;
            if (t_id != -1){
                freArr_ptr[t_id]++;
            }
        }
    }
}

int Subtask2::hashFunction1(std::string i) {
    int hashVal = 0;
    double modulo = 1e9+7;
    for (char c : i) {
        hashVal = (hashVal  + c) % static_cast<int>(modulo);
    }
    return hashVal;
}

int Subtask2::hashFunction2(std::string i) {
    const int p = 31;
    const int modu = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 3;
    for (char c : i) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % modu;
        p_pow = (p_pow * p) % modu;
    }
    return hash_value;
}

int Subtask2::binarySearch(int h1, int h2){
    int leftIndex= 0;
    int rightIndex = m;
    while(leftIndex <= rightIndex) {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
        // Compare middle element with the query
        if(tupleArr_ptr[middleIndex].hash_value1 == h1) {
            if(tupleArr_ptr[middleIndex].hash_value2 == h2){
                /*cout<<"binary search: "<< tupleArr_ptr[middleIndex].i << "  " <<  tupleArr_ptr[middleIndex].hash_value1<<"  "
                    <<  tupleArr_ptr[middleIndex].hash_value2<<"  " <<
                tupleArr_ptr[middleIndex].tuple_id<<endl;*/
                return tupleArr_ptr[middleIndex].tuple_id;
            }
            else if(tupleArr_ptr[middleIndex].hash_value2 > h2){
                leftIndex = middleIndex + 1;
            }
            else{
                rightIndex = middleIndex - 1;
            }
        }
        // If query greater, ignore left half
        if(tupleArr_ptr[middleIndex].hash_value1 > h1) {
            leftIndex = middleIndex + 1;
        }
        else {
            rightIndex = middleIndex - 1;
        }
    }
    return -1;
}
void Subtask2::printFrequency(){
    for(int i = 0; i<m; ++i){
        cout<<freArr_ptr[i]<<endl;
    }
}