/**
* Title: Binary Search Trees
* Author : ALARA ZEYBEK
* ID: 22102544
* Section : 3
* Homework : 1
* Description :
*/
#include <iostream>
#include "BST.h"
using namespace std;


BST::BST(){
    root = nullptr;
    nodeNum = 0;
}
BST::BST(int* keys, int size){
    root = nullptr;
    nodeNum = 0;
    for (int i = 0; i<size; i++){
        insertKeyWithoutPrint(keys[i]);
    }
    cout<< "BST with size "<<nodeNum<<" is created."<<endl;
}
BST::~BST(){
    destroyTree(root);
}

//Required Functions:
void BST::insertKeyWithoutPrint(int key){
    nodeNum++;
    if(!isEmpty()){
        BSTNode *tempPtr = root;
        insertHelper(key, tempPtr);
    }
    else{
        root = new BSTNode(key,nullptr,nullptr);
    }
}
void BST::insertKey(int key){
    if (searchForNode(root, key) != nullptr){
        cout << "Key "<< key << " is not added. It exists!"<< endl;
        return;
    }
    nodeNum++;
    cout << "Key "<< key << " is added.\n";
    if(!isEmpty()){
        BSTNode *tempPtr = root;
        insertHelper(key, tempPtr);
    }
    else{
        root = new BSTNode(key,nullptr,nullptr);
    }
}

void BST::deleteKeyWithoutPrint(int key){
    BSTNode *tempPtr = root;
    deleteHelper(key, tempPtr,0);
}
void BST::deleteKey(int key){
    BSTNode *tempPtr = root;
    deleteHelper(key, tempPtr,1);
}
void BST::displayInorder(){
    int i = 0;
    int lenght = nodeNum;
    cout<<"Inorder display is: ";
    if (lenght < 1){
        cout<<endl;
        return;
    }
    int* arr = new int[lenght];
    travHelper(lenght, arr, i, root);
    for (int j = 0; j < lenght-1; j++){
        cout<<arr[j]<<", ";
    }
    cout<<arr[lenght-1]<<endl;
    delete[] arr;
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

void BST::deleteHelper(int key, BSTNode* &ptr, bool printer){
    if(ptr == nullptr){
        cout << "Key "<< key<< " is not deleted. It does not exist!" << endl;
    }
    else if(ptr->item == key){
        deleteNodeItem(ptr,printer);
    }
    else if(ptr->item < key){
        deleteHelper(key, ptr->rightPtr,printer);
    }
    else{
        deleteHelper(key, ptr->leftPtr,printer);
    }
}
void BST::deleteNodeItem(BSTNode *&ptr, bool printer){
    BSTNode* dPtr;
    int rep;

    if(ptr->leftPtr == nullptr && ptr->rightPtr == nullptr){
        if(ptr == root){
            root = nullptr;
        }
        delete ptr;
        ptr = nullptr;
        nodeNum--;
        if (printer)
            cout<< "Key "<< ptr->item<<" is deleted."<<endl;
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
        if (printer)
            cout<< "Key "<< ptr->item<<" is deleted."<<endl;
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
        if (printer)
            cout<< "Key "<< ptr->item<<" is deleted."<<endl;
    }
    else{
        if (printer)
            cout<< "Key "<< ptr->item <<" is deleted."<<endl;
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
    //cout<<first<<" ";
    travHelper(size, arr, first, nodePtr->leftPtr);
    if(nodePtr != nullptr ){
        arr[first] = nodePtr->item;
        first++;
    }
    travHelper(size, arr, first, nodePtr->rightPtr);
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

//  -------------------------- LOWEST COMMON ANCESTOR ----------------------------
void BST::lowestCommonAncestor(int keyA, int keyB){
    if (searchForNode(root,keyA) == nullptr || searchForNode(root,keyB) == nullptr){
        cout<<"One or both key(s) cannot be found."<<endl;
        return;
    }
    int lca = lowestCommonAncestorHelper(keyA, keyB, root)->item;
    cout<< "Lowest common ancestor of "<<keyA<<" and "<<keyB<< " is: "<<lca<<endl;

}
BSTNode* BST::lowestCommonAncestorHelper(int keyA, int keyB, BSTNode* root){
    if (keyA == root->item || keyB == root->item){
        return root;
    }
    else if (keyA > root->item && keyB > root->item){
        return lowestCommonAncestorHelper(keyA, keyB, root->rightPtr);
    }
    else if(keyA < root->item && keyB < root->item){
        return lowestCommonAncestorHelper(keyA, keyB, root->leftPtr);
    }
    else{
        return root;
    }
}

//  -------------------------- FULL BTLEVEL ----------------------------
void BST::findFullBTLevel(){
    cout<<"Full binary tree level is: ";
    int a = findFullBTLevelHelper(root);
    cout << a << endl;
}

int BST::findFullBTLevelHelper(BSTNode* root){
    if (root == NULL ) {
        return 0;
    }
    else if(root->leftPtr == nullptr || root->rightPtr == nullptr){
        return 1;
    }
    return 1 + min(findFullBTLevelHelper(root->leftPtr), findFullBTLevelHelper(root->rightPtr));
}

//  -------------------------- MAX WIDTH ----------------------------
int BST::getHeight(BSTNode *root){
    if (root == nullptr)
        return 0;
    else {
        int lHeight = getHeight(root->leftPtr);
        int rHeight = getHeight(root->rightPtr);
        return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);

    }
}

void BST::maximumWidth(){
    int max_w = 0;
    int lowestlevel = 0;
    int height = getHeight(root);
    while ( height > 0 ){
        int garbage = 0;
        int* a = new int[nodeNum];
        int temp = maximumWidthHelper( root,  height,a, garbage);
        delete[] a;
        if (temp >= max_w){
            max_w = temp;
            lowestlevel = height;
        }
        height--;
    }
    cout << "Maximum level is: ";
    int *arr = new int[max_w];
    int l = 0;
    maximumWidthHelper( root,  lowestlevel,arr, l);
    for ( int i = 0; i < max_w; i++){
        if (i == max_w-1){
            cout<<arr[i];
        }
        else{
            cout<<arr[i]<<", ";
        }
    }
    cout<< endl;
    delete[] arr;
}

int BST::maximumWidthHelper(BSTNode* root, int counter, int* &arr, int &size){
    if (root == nullptr)
        return 0;
    if (counter == 1) {
        arr[size] = root->item;
        size++;
        return 1;
    }
    else if (counter > 1)
        return maximumWidthHelper(root->leftPtr, counter - 1, arr, size)
               + maximumWidthHelper(root->rightPtr, counter - 1, arr , size);
    return 0;
}

//  -------------------------- MAX PATH ----------------------------

void BST::maximumSumPath(){
    if (root == nullptr) {
        return;
    }
    BSTNode* target_leaf;
    int max_sum = -666666666;
    maxSumPathHelperToReachTargetLeaf(root, &max_sum, 0, &target_leaf);

    cout<< "Maximum sum path is: ";
    int* arr = new int[nodeNum];
    int size = 0;
    printMaxPath(root, target_leaf,arr,size);
    if (size > 0) {
        for (int i = size - 1; i > 0; i--) {
            cout << arr[i] << ", ";
        }
        cout << arr[0]<<endl;
    }
    delete[] arr;
}

void BST::maxSumPathHelperToReachTargetLeaf(BSTNode* r, int* max_sum_ref, int curr_sum, BSTNode** target_leaf_ref){
    if (r == nullptr) {
        return;
    }
    curr_sum = curr_sum + r->item;

    if (r->leftPtr == nullptr && r->rightPtr == nullptr) {
        if (curr_sum > *max_sum_ref) {
            *max_sum_ref = curr_sum;
            *target_leaf_ref = r;
        }
    }
    maxSumPathHelperToReachTargetLeaf(r->leftPtr, max_sum_ref, curr_sum,
                  target_leaf_ref);
    maxSumPathHelperToReachTargetLeaf(r->rightPtr, max_sum_ref, curr_sum,
                  target_leaf_ref);
}

bool BST::printMaxPath(BSTNode* root, BSTNode* target_leaf, int* &arr, int &size){
    if (root == nullptr) {
        return false;
    }
    if (root == target_leaf || printMaxPath(root->leftPtr, target_leaf, arr, size) ||
        printMaxPath(root->rightPtr, target_leaf,arr, size)) {
        arr[size] = root->item;
        size++;
        return true;
    }
    return false;
}

/*
// LCA
BSTNode* BST::pathFromAtoBHelper(int keyA, int keyB,BSTNode* root){
    if (keyA <= root->item && keyB >= root->item ||
        keyA >= root->item && keyB <= root->item){
        return root;
    }
    else if (keyA > root->item && keyB > root->item){
        return pathFromAtoBHelper(keyA, keyB, root->rightPtr);
    }
    else if (keyA < root->item && keyB < root->item){
        return pathFromAtoBHelper(keyA, keyB, root->leftPtr);
    }
    return nullptr;
}
*/
//  -------------------------- PATH FROM A TO B ----------------------------
void BST::pathFromAtoB(int keyA, int keyB) {
    BSTNode* temp = root;
    const int MAX_PATH_LENGTH = 1000; // Adjust as needed
    int pathA[MAX_PATH_LENGTH], pathB[MAX_PATH_LENGTH];
    int pathLengthA = 0, pathLengthB = 0;

    temp = lowestCommonAncestorHelper(keyA,keyB, root);
    if (findPath(temp, keyA, pathA, pathLengthA) && findPath(temp, keyB, pathB, pathLengthB)) {
        cout << "Path from " << keyA << " to " << keyB << " is: ";

        int commonAncestor = -1;
        for (int i = 0; i < pathLengthA; ++i) {
            //std::cout << pathA[i] << ",";
            for (int j = 0; j < pathLengthB; ++j) {
                if (pathA[i] == pathB[j]) {
                    commonAncestor = pathA[i];
                    break;
                }
            }
        }
        // Print the path from the common ancestor to B
        for (int i = pathLengthA - 1; i >= 0; --i) {
            cout << pathA[i] << ", ";
            if (pathA[i] == commonAncestor) {
                break;
            }
        }
        if (commonAncestor != keyB) {
            for (int i = 0; i < pathLengthB; ++i) {
                if (pathB[i] == commonAncestor) {
                    continue;
                }
                if (i == pathLengthB-1){
                    cout << pathB[i];
                }
                else{
                    cout << pathB[i] << ", ";
                }
            }
        }
        cout << endl;
    } else {
        cout << "One or both keys not found in the BST.\n";
    }
}

bool BST::findPath(BSTNode* root, int key, int path[], int& pathLength) {
    if (root == nullptr) {
        return false;
    }

    path[pathLength++] = root->item;

    if (key == root->item) {
        return true;
    }

    if (key < root->item && findPath(root->leftPtr, key, path, pathLength)) {
        return true;
    }

    if (key > root->item && findPath(root->rightPtr, key, path, pathLength)) {
        return true;
    }

    pathLength--;
    return false;
}