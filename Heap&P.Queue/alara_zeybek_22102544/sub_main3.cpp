
#include <iostream>
#include "Subtask3.h"
#include <string>
using namespace std;

int main(int argc, char *argv[]){
    freopen(argv[1], "r", stdin);
    if( argc > 2 ){
        freopen(argv[2], "w", stdout);
    }
    int n = 0;
    string input = "";
    scanf("%d",&n);
    string str[n];
    for( int i = 1; i <= n; i++){
        cin >> input;
        for (char& c : input) {
            c = tolower(c); // Convert each character to lowercase
        }
        str[i] = input;
    }
    //string a[] = {"baaa","aaab", "bcd","dcb"};
    //int n = 4;
    Subtask3(str,  n);

}