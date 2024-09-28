/**
* Title: Binary Search Trees
* Author : ALARA ZEYBEK
* ID: 22102544
* Section : 3
* Homework : 2
* Description :
*/
#ifndef BSTNODE_H
#define BSTNODE_H

using namespace std;
class BSTNode{

    public:
        BSTNode();
        ~BSTNode();
        BSTNode(const int& nodeItem, BSTNode *left , BSTNode *right );

        int item;       // data portion
        BSTNode *leftPtr;  // pointer to left child
        BSTNode *rightPtr; // pointer to right child

    friend class BST;
};

#endif