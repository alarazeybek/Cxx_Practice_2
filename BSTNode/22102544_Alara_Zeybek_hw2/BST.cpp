/**
* Title: Binary Search Trees
* Author : ALARA ZEYBEK
* ID: 22102544
* Section : 3
* Homework : 2
* Description :
*/
#include <iostream>
#include "BST.h"
#include <stack>
using namespace std;
    
                
    BST::BST(){
        root = nullptr;
        nodeNum = 0;
    }
    BST::BST(const int& rootItem){
        root = new BSTNode(rootItem,nullptr,nullptr);
        nodeNum = 0;
    }
    BST::~BST(){
        destroyTree(root);
    }

    //Required Functions:
    void BST::insertItem(int key){
        nodeNum++;
        if(!isEmpty()){
            BSTNode *tempPtr = root;
            insertHelper(key, tempPtr);
        }
        else{
            root = new BSTNode(key,nullptr,nullptr);
        }
    }
    void BST::deleteItem(int key){
        BSTNode *tempPtr = root;
        deleteHelper(key, tempPtr);
    }
    int* BST::inorderTraversal(int &lenght){
        int i = 0;
        int* arr = new int[lenght];
        travHelper(lenght, arr, i, root);
        return arr;
    }
    //Helper Methods:
    void BST::insertHelper(int key, BSTNode* &tempPtr){
        if (tempPtr == NULL) {
			tempPtr = new BSTNode(key, NULL, NULL);
		}
		else if (key < tempPtr->item) 
			insertHelper(key,tempPtr->leftPtr);
		else
			insertHelper(key,tempPtr->rightPtr);
    }
    void BST::destroyTree( BSTNode* &tempPtr){
        if(tempPtr == nullptr){
            return;
        }
        destroyTree(tempPtr->rightPtr);
        destroyTree(tempPtr->leftPtr);
        delete tempPtr;
        tempPtr=nullptr;
    }
    bool BST::isEmpty(){
        return root == nullptr;
    }
    void BST::printBST(BSTNode* p){
        if(p == nullptr){
            return;
        }
        cout<<p->item<<endl;
        printBST(p->leftPtr);
        printBST(p->rightPtr);
    }

void BST::deleteHelper(int key, BSTNode* &ptr){
    if(ptr == nullptr){
        cout << "The item cannot be deleted because it does not exist" << endl;
    }
    else if(ptr->item == key){
        deleteNodeItem(ptr);
    }
    else if(ptr->item < key){
        deleteHelper(key, ptr->rightPtr);
    }
    else{
        deleteHelper(key, ptr->leftPtr);
    }
}
void BST::deleteNodeItem(BSTNode *&ptr){
    BSTNode* dPtr;
    int rep;

    if(ptr->leftPtr == nullptr && ptr->rightPtr == nullptr){
        if(ptr == root){
            root = nullptr;
        }
        delete ptr;
        ptr = nullptr;
        nodeNum--;
    }
    else if(ptr->rightPtr == nullptr){
        if(ptr == root){
            root = ptr->leftPtr;
        }
        dPtr = ptr;
        ptr = ptr->leftPtr;
        dPtr->leftPtr = nullptr;
        delete dPtr;
        dPtr = nullptr;
        nodeNum--;
    }
    else if(ptr->leftPtr == nullptr){
        if(ptr == root){
            root = ptr->rightPtr;
        }
        dPtr = ptr;
        ptr = ptr->rightPtr;
        dPtr->rightPtr = nullptr;
        delete dPtr;
        dPtr = nullptr;
        nodeNum--;
    }
    else{
        processLeftmost(ptr->rightPtr, rep);
        ptr->item = rep;
    }
}
    void BST::processLeftmost(BSTNode *& nodePtr, int& treeItem){
        if(nodePtr->leftPtr == nullptr){
            treeItem = nodePtr->item;
            BSTNode* del = nodePtr;
            nodePtr = nodePtr->rightPtr;
            del->rightPtr = nullptr;
            delete del;
            nodeNum--;
        }
        else{
            processLeftmost(nodePtr->leftPtr, treeItem);
        }
    }
    void BST::travHelper(int &size,  int*& arr, int& first, BSTNode* nodePtr){
        if(nodePtr == nullptr){
            return;
        }
        if(first >= size){
            return;
        }
        //cout<<first<<endl;
        travHelper(size, arr, first, nodePtr->leftPtr);
        if(nodePtr != nullptr ){
            arr[first] = nodePtr->item;
            first++;
        }
        travHelper(size, arr, first, nodePtr->rightPtr);
    }
    bool BST::hasSequenceHelper(int*& seq, int length){
        //if(seq != nullptr) {
            int arr[length];
            int *a = arr;
            BSTNode *initial = searchForNode(root, seq[0]);
            int i = 0;
            travHelper(length, (a), i, initial);
            cout<<"KKKKKKKKKKKKKKKKK = i : "<<i<<endl;
            i = 0;
            while (i < length) {
                cout<<arr[i]<<"  *****    "<< seq[i]<<endl;
                if (arr[i] != seq[i]) {
                    return 0;
                }
                i++;
            }
            return 1;
        //}
        //return 0;
        /*int i = 0;
        BSTNode *initial = searchForNode(root, seq[0]);
        return hasSequenceHelper(initial, seq, length, i);*/
    }
    bool BST::hasSequence(int* seq, int length) {
        if (!root || length == 0) {
            return false;
        }
        BSTNode* tempStart = root;
        stack<BSTNode*> leftStack;
        int point = 0;

        while (tempStart!= nullptr || !leftStack.empty()) {
            while (tempStart != nullptr) {
                leftStack.push(tempStart);
                tempStart = tempStart->leftPtr;
            }
            tempStart = leftStack.top();
            leftStack.pop();
            if (point < length && tempStart->item == seq[point]) {
                point++;
            }
            else {
                point = 0;
            }
            if (point == length) {
                return true;
            }
            tempStart = tempStart->rightPtr;
        }
        if (point != length) {
            return false;
        }
        else{
            return true;
        }
    }
    BSTNode* BST::searchForNode(BSTNode* firstNode, int& key){
        if(firstNode == nullptr){
            return nullptr;
        }
        else if( key == firstNode->item ){
            return firstNode;
        }
        if(firstNode->item > key){
            return searchForNode(firstNode->leftPtr, key);
        }
        else {
            return searchForNode(firstNode->rightPtr, key);
        }
}
    int BST::getNodeNumFrom(BSTNode* node){
        if(node == nullptr){
            return 0;
        }
        return 1 + getNodeNumFrom(node->rightPtr) + getNodeNumFrom(node->leftPtr);
    }
    BST* BST::merge(const BST& tree1, const BST& tree2){
      /*  BST b = tree1;
        BST d = tree2;
        return mergeHelper( b, d);*/
        int i = 0, k = 0;
        int size1 = tree1.nodeNum;
        int size2 = tree2.nodeNum;
        int* fPart = const_cast<BST&>(tree1).inorderTraversal(size1);
        int* sPart = const_cast<BST&>(tree2).inorderTraversal(size2);
        BST* result = new BST();
        while(i<size1){
            result->insertItem(fPart[i]);
            i++;
        }
        while(k<size2){
            result->insertItem(sPart[k]);
            k++;
        }
        delete[] fPart;
        delete[] sPart;
        return result;
    }

    BST* BST::mergeHelper(BST& tree1, BST& tree2){
        int i = 0, k = 0;
        int size1 = tree1.nodeNum;
        int size2 = tree2.nodeNum;
        int* fPart = tree1.inorderTraversal(size1);
        int* sPart = tree2.inorderTraversal(size2);
        BST* result = new BST();
        while(i<size1){
            result->insertItem(fPart[i]);
            i++;
        }
        while(k<size2){
            result->insertItem(sPart[k]);
            k++;
        }
        delete[] fPart;
        delete[] sPart;
        return result;
    }