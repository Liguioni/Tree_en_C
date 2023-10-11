#include "Tree.h"

int main() {
    Tree *tree = createTree();
    Node *node1 = createNode('A');
    Node *node2 = createNode('B');
    Node *node3 = createNode('C');
    Node *node4 = createNode('D');
    addLeftToNode(node1, node2);
    addRightToNode(node1, node3);
    addLeftToNode(node3, node4);
    tree->root = node1;
    displayTree(*tree);
    printf("Height: %d\n", getTreeHeight(*tree));
    printf("Num of nodes: %d\n", countNodesInTree(*tree));
    printf("Minimum value: %c\n", findMinimumValueInTree(*tree));
    return 0;
}
