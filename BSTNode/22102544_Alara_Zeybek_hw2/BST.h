/**
* Title: Binary Search Trees
* Author : ALARA ZEYBEK
* ID: 22102544
* Section : 3
* Homework : 2
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
        //bool deleted = 0;

        BST();
        BST(const int& rootItem);
        ~BST();

        //Required Functions:
        void insertItem(int key); 
        void deleteItem(int key); 
        int* inorderTraversal(int& length); 

        //Helper Methods:
        //private:
        bool isEmpty();
        int getHeight();
        void insertHelper(int key, BSTNode* &tempPtr);
        void deleteHelper(int key, BSTNode*& pPtr);
        void printBST(BSTNode* p);
        void deleteNodeItem(BSTNode * &nodePtr);
        void processLeftmost(BSTNode *&nodePtr,int& treeItem);
        void destroyTree( BSTNode* &tempPtr);
        void travHelper(int &size,  int*& arr, int& first, BSTNode* nodePtr);
        bool hasSequence(int* seq, int length);
        bool hasSequenceHelper(int*& seq, int length);
        int getNodeNumFrom(BSTNode* node);

        BSTNode* searchForNode(BSTNode* firstNode, int& key);
        BST* merge(const BST& tree1, const BST& tree2);
        BST* mergeHelper(BST& tree1, BST& tree2);
};
#endif