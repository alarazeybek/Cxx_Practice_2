/**
* Title: Binary Search Trees
* Author : ALARA ZEYBEK
* ID: 22102544
* Section : 3
* Homework : 1
* Description :
*/
#include <iostream>
#include "BSTNode.h"
using namespace std;

BSTNode::BSTNode(){}

BSTNode::BSTNode(const int& nodeItem, BSTNode *left , BSTNode *right) {
    item = nodeItem;
    leftPtr = left;
    rightPtr = right;
}

BSTNode::~BSTNode(){
    /*if(leftPtr != nullptr){
        delete leftPtr;
    }
    if(rightPtr != nullptr){
        delete rightPtr;
    }*/
}

        