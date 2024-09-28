/**
* Title: Binary Search Trees
* Author : ALARA ZEYBEK
* ID: 22102544
* Section : 3
* Homework : 1
* Description :
*/
#ifndef BST_H
#define BST_H
#include <iostream>
#include "BSTNode.h"

using namespace std;

class BST{
public:
    BSTNode *root;
    int nodeNum;

    BST();
    BST(int* keys, int size);
    ~BST();

    //Required Functions:
    void insertKey(int key);
    void deleteKey(int key);
    void displayInorder();

    //Helper Methods:
    //private:
    bool isEmpty();
    void insertKeyWithoutPrint(int key);
    void deleteKeyWithoutPrint(int key);
    int getHeight(BSTNode *root);
    void insertHelper(int key, BSTNode* &tempPtr);
    void deleteHelper(int key, BSTNode*& pPtr,bool printer);
    void deleteNodeItem(BSTNode * &nodePtr,bool printer);
    void processLeftmost(BSTNode *&nodePtr,int& treeItem);
    void destroyTree( BSTNode* &tempPtr);
    void travHelper(int &size,  int*& arr, int& first, BSTNode* nodePtr);
    int getNodeNumFrom(BSTNode* node);

    BSTNode* searchForNode(BSTNode* firstNode, int& key);
    void findFullBTLevel();
    int findFullBTLevelHelper(BSTNode* root);
    void lowestCommonAncestor(int keyA, int keyB);
    BSTNode* lowestCommonAncestorHelper(int keyA, int keyB, BSTNode* root);
    void maximumWidth();
    int maximumWidthHelper(BSTNode* root, int counter,  int* &arr, int &size);

    void pathFromAtoB(int keyA, int keyB);
    bool findPath(BSTNode* root, int key, int path[], int& pathLength);

    void maxSumPathHelperToReachTargetLeaf(BSTNode* Node, int* max_sum_ref, int curr_sum, BSTNode** target_leaf_ref);
    void maximumSumPath();
    bool printMaxPath(BSTNode* root, BSTNode* target_leaf, int* &arr, int &size);
};
#endif