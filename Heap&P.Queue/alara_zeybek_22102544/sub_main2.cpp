//
// Created by DELL on 30.04.2024.
//
#include <iostream>
#include "Subtask2.h"
using namespace std;

int main(int argc, char *argv[]){
    freopen( argv[1], "r", stdin );
    if( argc > 2 ){
        freopen( argv[2], "w", stdout );
    }
    string subtask2_str = "";
    cin >> subtask2_str;

    int n = subtask2_str.size();
    int m = 0;
    scanf( "%d", &m);
    string tuples[m];
    for( int i = 0; i < m; i++ ){
        cin >> tuples[i];
    }
    Subtask2 s2(subtask2_str, tuples, n, m);
}