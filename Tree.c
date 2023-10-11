//
// Created by lucbe on 11/10/2023.
//
#include "Tree.h"
#include <math.h>

void displayNodeAndChildren(Node *pNode);

int getNodeHeight(Node *pNode);

int countNodesFromRoot(Node *pNode);

char findMinimumValueInNodes(Node *pNode);

Tree *createTree() {
    Tree *newTree = (Tree *) malloc(sizeof(Tree));
    newTree->root = NULL;
    return newTree;
}

Node *createNode(char value) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addLeftToNode(Node *node, Node *left) {
    node->left = left;
}

void addRightToNode(Node *node, Node *right) {
    node->right = right;
}

void displayTree(Tree tree) {
    if (tree.root != NULL) {
        displayNodeAndChildren(tree.root);
        printf("\n");
    }
}

void displayNodeAndChildren(Node *node) {
    if (node == NULL) {
        printf("_");
    } else {
        printf("[%c](", node->value);
        displayNodeAndChildren(node->left);
        printf(",");
        displayNodeAndChildren(node->right);
        printf(")");
    }
}

int getTreeHeight(Tree tree) {
    return getNodeHeight(tree.root);
}

int getNodeHeight(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + fmax(getNodeHeight(node->left), getNodeHeight(node->right));
}

int countNodesInTree(Tree tree) {
    return countNodesFromRoot(tree.root);
}

int countNodesFromRoot(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + countNodesFromRoot(node->left) + countNodesFromRoot(node->right);
}

char findMinimumValueInTree(Tree tree) {
    return findMinimumValueInNodes(tree.root);
}

char findMinimumValueInNodes(Node *node) {
    if (node == NULL) {
        return (char) 127;
    }
    return (char) fmin((double) node->value,
                       fmin((double) findMinimumValueInNodes(node->left),
                            (double) findMinimumValueInNodes(node->right)));
}
