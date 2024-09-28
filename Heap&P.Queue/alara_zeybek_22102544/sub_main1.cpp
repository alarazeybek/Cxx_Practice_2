
#include <iostream>
#include "Hashing.h"
using namespace std;

int main(int argc, char *argv[]){
    freopen( argv[1], "r", stdin );
    if( argc > 2 ){
        freopen( argv[2], "w", stdout );
    }

    Hashing hashTable;
    int n = 0;
    scanf("%d",&n);
    string subtask1_str[n];
    for( int i = 1; i <= n; i++){
        cin >> subtask1_str[i];
    }
    //string a[] = {"ab","abc","abdce","bc","bcda","c","cab","bca","def","ef"};
    hashTable.WordFilter(subtask1_str,n);
    //hashTable.printTable();
    cout << (hashTable.searchCollision(subtask1_str,n)) << endl;
}