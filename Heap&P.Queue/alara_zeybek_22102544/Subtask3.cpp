//
// Created by DELL on 29.04.2024.
//

#include <algorithm>
#include "Subtask3.h"
#include <iostream>
using namespace std;

bool Subtask3::comparetupleTask3(const tupleTask3& a, const tupleTask3& b) {
    // First, compare by hash1 in descending order
    if (a.hash_value_unique1 != b.hash_value_unique1) {
        return a.hash_value_unique1 > b.hash_value_unique1;
    }
    // If hash1 values are equal, compare by hash2
    return a.hash_value_unique2 > b.hash_value_unique2;
}
Subtask3::Subtask3(string *tuple_list, int n_val) {
    minimal_subset = 0;
    reverse_count = 0;
    n = n_val;
    tupleArr_ptr = new tupleTask3[n];
    visitedArr_ptr = new bool[n];
    // initializing the frequencies.
    for (int i = 0; i < n; ++i){
        visitedArr_ptr[i] = false;
    }
    // initializing the tuples.
    int tuple_id = 0;
    for (int i = 0; i < n; ++i) {
        string tuple = tuple_list[i];
        int hash_val1 = hashFunction1(tuple);
        int hash_val2 = hashFunction2(tuple);
        long long hash_valU1 = hashFunctionUnique1(tuple);
        long long hash_valU2 = hashFunctionUnique2(tuple);
        tupleArr_ptr[i] = tupleTask3(tuple, hash_val1, hash_val2, hash_valU1, hash_valU2, tuple_id++); // adding tuple
    }
    for (int i = 0; i < n; ++i) {
        if( !visitedArr_ptr[i] ) {
            minimal_subset++;
            visitedArr_ptr[i] = true;
            string tuple = tupleArr_ptr[i].str;

            int length = tuple.size();
            string temp = tuple;
            int countLeft = 0;
            int countRight = 0;
            countLeft++;
            for( int j= 0; j < length - 1; j++ ){
                string right = temp.substr( 1, length - 1);
                right.append( temp.substr(0,1));
                temp = right;
                int hash_val1 = hashFunction1(temp);
                int hash_val2 = hashFunction2(temp);
                long long hash_valU1 = hashFunctionUnique1(temp);
                long long hash_valU2 = hashFunctionUnique2(temp);

                int id = -1;
                for (int a = 0; a < n; a++){
                    tupleTask3 tempT = tupleArr_ptr[a];
                    if(tempT.hash_value_unique1 == hash_valU1 && tempT.hash_value_unique2 == hash_valU2){
                        id = tupleArr_ptr[a].tuple_id;
                    }
                }
                if ( id != -1 ){
                    visitedArr_ptr[id] = true;
                    countLeft++;
                }
            }
            temp = tuple;
            reverse( temp.begin(), temp.end());
            for( int j= 0; j < length; j++ ){
                int hash_val1 = hashFunction1(temp);
                int hash_val2 = hashFunction2(temp);
                long long hash_valU1 = hashFunctionUnique1(temp);
                long long hash_valU2 = hashFunctionUnique2(temp);
                //int id = binarySearch( hash_val1, hash_val2, hash_valU1, hash_valU2, true );
                int id = -1;
                for (int a = 0; a < n; a++){
                    tupleTask3 tempT = tupleArr_ptr[a];
                    if(tempT.hash_value_unique1 == hash_valU1 && tempT.hash_value_unique2 == hash_valU2){
                        id = tupleArr_ptr[a].tuple_id;
                    }
                }
                if ( id != -1  && !visitedArr_ptr[id]){
                    visitedArr_ptr[id] = true;
                    countRight++;
                }
                string right = temp.substr( 1, length - 1);
                right.append( temp.substr(0,1));
                temp = right;
            }
            reverse_count += min ( countLeft, countRight );
        }
    }
    printResults();
}

Subtask3::~Subtask3(){
    delete[] visitedArr_ptr;
    delete[] tupleArr_ptr;
}



int Subtask3::hashFunction1(std::string i) {
    int hashVal = 0;
    double modulo = 1e9+7;
    for (char c : i) {
        hashVal = (hashVal  + c) % static_cast<int>(modulo);
    }
    return hashVal;
}

int Subtask3::hashFunction2(std::string i) {
    int hashVal = 0;
    double modulo = 1e9+9;
    for (char c : i) {
        hashVal = (hashVal  + c) % static_cast<int>(modulo);
    }
    return hashVal;
}
long long Subtask3::hashFunctionUnique1(std::string i) {
    const int p = 2;
    const int modu = 1e9 + 7;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : i) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % modu;
        p_pow = (p_pow * p) % modu;
    }
    return hash_value;
}
long long Subtask3::hashFunctionUnique2(std::string i) {
    const int p = 3;
    //const int modu = 1e9 + 9;
    const int modu = 101;
    long long hash_value = 0;
    long long p_pow = 1;
    for (int j = 0; j < i.size(); ++j) {
        hash_value = (hash_value + (i[j] - 'a' + 1) * p_pow) % modu;
        p_pow = (p_pow * p) % modu;
    }
    return hash_value;
}

void Subtask3::printResults(){
    cout<<reverse_count<<endl;
    cout<<minimal_subset<<endl;
}
void Subtask3::printVisited(){
    cout<<"printing bools: ";
    for(int i = 0 ; i < n; i++){
        cout<< "i-"<<i<<"->"<<visitedArr_ptr[i]<<endl;
    }
}