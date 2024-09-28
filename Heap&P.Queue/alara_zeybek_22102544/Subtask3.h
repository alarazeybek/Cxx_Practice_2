//
// Created by DELL on 30.04.2024.
//

#ifndef CS202_HW3_SUBTASK3_H
#define CS202_HW3_SUBTASK3_H
#include <string>

using namespace std;

struct tupleTask3 : public basic_string<char> {
    int hash_value1;
    int hash_value2;
    long long hash_value_unique1;
    long long hash_value_unique2;
    int tuple_id;
    string str;
    tupleTask3(string string_val, int h1, int h2, long long h1_unique, long long h2_unique, int index){
        str = string_val;
        hash_value1 = h1;
        hash_value2 = h2;
        hash_value_unique1 = h1_unique;
        hash_value_unique2 = h2_unique;
        tuple_id = index;
    }
    tupleTask3(){};
    ~tupleTask3(){};
};
class Subtask3 {
public:
    Subtask3(string* tuple_list, int n);
    ~Subtask3();

    void printResults();
private:
    int n;
    int minimal_subset;
    int reverse_count;
    tupleTask3* tupleArr_ptr;
    //frequencyTask2* freArr_ptr;
    bool* visitedArr_ptr;

    int hashFunction1(string i);
    int hashFunction2(string i);
    long long hashFunctionUnique1(string i);
    long long hashFunctionUnique2(string i);


    void printVisited();
    static bool comparetupleTask3(const tupleTask3& a, const tupleTask3& b);

};


#endif //CS202_HW3_SUBTASK3_H
