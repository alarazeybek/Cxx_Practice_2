//
// Created by DELL on 29.04.2024.
// Applicability analysis -> 2. ev 4. farkı ne?
// Upper threshold of cost nereden belirlendi



// Why did not you consider time cost

#ifndef CS202_HW3_SUBTASK2_H
#define CS202_HW3_SUBTASK2_H
#include <string>

using namespace std;
struct tupleTask2{
    int hash_value1;
    int hash_value2;
    int tuple_id;
    string i;
    tupleTask2(string string_val, int h1, int h2, int index){
        hash_value1 = h1;
        hash_value2 = h2;
        i = string_val;
        tuple_id = index;
    }
    tupleTask2(){};
    ~tupleTask2(){};
};
struct frequencyTask2{
    int fre1;
    string i;
    frequencyTask2(int f1,string string_val){
        fre1 = f1;
        i = string_val;
    }
};

class Subtask2 {
public:
    Subtask2(string str, string* tuple_list, int n, int m);
    ~Subtask2();

    void printFrequency();
private:
    string main_str;
    int n;
    int m;
    int k;
    tupleTask2* tupleArr_ptr;
    //frequencyTask2* freArr_ptr;
    int* freArr_ptr;

    int hashFunction1(string i);
    int hashFunction2(string i);

    void traverseStringInKParts();

    // Sorting
    static bool comparetupleTask2(const tupleTask2& a, const tupleTask2& b); // for std::sort()
    // Search
    int binarySearch(int h1, int h2);
};


#endif //CS202_HW3_SUBTASK2_H
