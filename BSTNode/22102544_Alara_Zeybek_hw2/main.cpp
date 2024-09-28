/**
* Title: Binary Search Trees
* Author : ALARA ZEYBEK
* ID: 22102544
* Section : 3
* Homework : 2
* Description : main
*/
#include <iostream>
#include "BST.h"
#include "BSTNode.h"
#include "analysis.h"
using namespace std;

void timeAnalysis();
void printArray(string const treeName, int const arraySize, int* arr);

int main(){
    BST firstTree;
    firstTree.insertItem(8);
    firstTree.insertItem(15);
    firstTree.insertItem(10);
    firstTree.insertItem(4);
    firstTree.insertItem(9);
    firstTree.insertItem(6);
    firstTree.insertItem(16);
    firstTree.insertItem(5);
    firstTree.insertItem(7);
    firstTree.insertItem(14);

    int* tempArr ;
    tempArr = firstTree.inorderTraversal(firstTree.nodeNum);
    printArray("FirstTree", firstTree.nodeNum, tempArr);
    delete[] tempArr;

    firstTree.deleteItem(7);
    firstTree.deleteItem(10);
    firstTree.deleteItem(8);
    firstTree.deleteItem(9);
    firstTree.deleteItem(5);

    tempArr = firstTree.inorderTraversal(firstTree.nodeNum);
    printArray("FirstTree", firstTree.nodeNum, tempArr);
    delete[] tempArr;

    BST secondTree;
    secondTree.insertItem(44);
    secondTree.insertItem(-5);
    secondTree.insertItem(0);
    secondTree.insertItem(3);
    secondTree.insertItem(4);
    secondTree.insertItem(22);
    secondTree.insertItem(-1);

    int* tempArr2 ;
    tempArr2 = secondTree.inorderTraversal(secondTree.nodeNum);
    printArray("SecondTree", secondTree.nodeNum, tempArr2);
    delete[] tempArr2;

    cout<<"Has Sequence Check1: Expected is 1\n";
        int* arr = new int[3];
        arr[0] = 4;
        arr[1] = 22;
        arr[2] = 44;
        cout << secondTree.hasSequence(arr, 3) << endl;
        delete[] arr;
        arr = nullptr;

    cout<<"Has Sequence Check2: Expected is 0\n";
        arr = new int[5];
        arr[0] = 22;
        arr[1] = 4;
        arr[2] = 3;
        arr[3] = 0;
        arr[4] = -5;
        cout << secondTree.hasSequence(arr, 5) << endl;
        delete[] arr;
        arr = nullptr;

    BST* newNode;
    newNode = (firstTree.merge(firstTree, secondTree));
    int size = firstTree.nodeNum + secondTree.nodeNum;
    arr = newNode->inorderTraversal(size);
    printArray("Merged Tree", size, arr);
    delete newNode;
    delete[] arr;
    timeAnalysis();
    return 0;
    }

void timeAnalysis(){
    int SIZE = 15000;
    int partSIZE = 1500;
    cout<<"Part e - Time Analysis of Binary Search Tree - part 1\n";
    cout<<"-----------------------------------------------------\n";
    cout<<"Tree Size    Time Elapsed\n";
    cout<<"-----------------------------------------------------\n";
    BST* tree = new BST;
    analysis a;
    int* arr = nullptr;
    a.createArr(arr,SIZE);
    double start1 = clock();
    for(int i = 0; i<SIZE; i+= partSIZE ) {
        start1 = 0;
        a.insertBST(arr, partSIZE, i, tree);
        double duration1 = 1000 * double(clock() - start1) / CLOCKS_PER_SEC;
        cout << i + partSIZE << "           " << duration1 << "ms"<< endl;
    }
    cout<<"Part e - Time Analysis of Binary Search Tree - part 2\n";
    cout<<"-----------------------------------------------------\n";
    cout<<"Tree Size    Time Elapsed\n";
    cout<<"-----------------------------------------------------\n";
    a.Shuffle(arr,SIZE);
    double start2 = clock();
    for(int i = 0; i<SIZE; i+= partSIZE){
        start2 = 0;
        a.onlyDelete(arr, tree, partSIZE, i);
        double duration2 = 1000 * double( clock() - start2 ) / CLOCKS_PER_SEC;
        cout<<i+partSIZE<<"           "<<duration2<<"ms"<<endl;
    }
    delete[] arr;
    delete tree;
}

void printArray(string const treeName, int const arraySize, int* arr){
    cout<<"Nodes in the tree "<<treeName<<" :\n";
    for(int i = 0; i<arraySize;i++){
        cout<<arr[i]<<endl;
    }
}