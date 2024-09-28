//
// Created by DELL on 25.02.2024.
//

#ifndef POPO_BSTNODE_H
#define POPO_BSTNODE_H


class BSTNode {
    public:
    BSTNode();
    ~BSTNode();
    BSTNode(const int& nodeItem, BSTNode *left , BSTNode *right );

    int item;       // data portion
    BSTNode *leftPtr;  // pointer to left child
    BSTNode *rightPtr; // pointer to right child

    friend class BST;
};


#endif //POPO_BSTNODE_H
