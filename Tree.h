//
// Created by lucbe on 11/10/2023.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef UNTITLED_TREE_H
#define UNTITLED_TREE_H

typedef struct Node {
    char value;
    struct Node* left;
    struct Node* right;
}Node;

typedef struct Tree {
    Node *root;
}Tree;

Tree *createTree();

Node *createNode(char value);

void addLeftToNode(Node *node, Node *left);

void addRightToNode(Node *node, Node *right);

void displayTree(Tree tree);

int getTreeHeight(Tree tree);

int countNodesInTree(Tree tree);

char findMinimumValueInTree(Tree tree);

#endif //UNTITLED_TREE_H
